

#include "omg_serv.h"

#include "SerialPort.h"

#include <stdio.h>
#include <stdlib.h>


// using only because I do not want to fuck with windows.h
#include <thread>
#include <chrono>

#define KEEP_MEASURES 12
#define PORTS_N 5
#define REFRESH_TIME 10ms

// гении мелкомягкие не поддерживают возврат значення из макро
#define AVERAGE(arr, target) do{uint32_t buffer_sum=0; for(uint16_t _i=0;_i<KEEP_MEASURES;_i++) {buffer_sum+=(arr)[_i];}; target=buffer_sum/KEEP_MEASURES;}while(0)

struct omg_serial_serv_t {
	SerialPort* file_handler;
	omg_serial_input_callback_f input_callback;
	omg_serial_error_callback_f error_callback;
	std::thread* thr_handler;
	unsigned state;
	uint16_t last_measures[PORTS_N][KEEP_MEASURES];
	uint16_t begin_ind;
	uint16_t current_lo[PORTS_N];
	uint16_t current_hi[PORTS_N];
	OMGERRSTAT current_error;
};


omg_serial_serv_t *omg_serv_new(const char* portname) {
	if (!portname) return NULL;
	omg_serial_serv_t *server = (omg_serial_serv_t*)calloc(1, sizeof(omg_serial_serv_t));
	server->file_handler = new SerialPort(portname);
	return server;
}


void omg_serv_free(omg_serial_serv_t* serv) {
	if (!serv) return;

	if (serv->thr_handler) {
		serv->state = 0;
		serv->thr_handler->join();
		delete serv->thr_handler;
	}
	
	if (serv->file_handler) {
		serv->file_handler->closeSerial();
		delete serv->file_handler;
	}

	free(serv);
}


void omg_serv_set_input(omg_serial_serv_t* serv, omg_serial_input_callback_f call_f) {
	if (!serv) return;
	serv->input_callback = call_f;
}

void omg_serv_set_error(omg_serial_serv_t* serv, omg_serial_error_callback_f call_f) {
	if (!serv) return;
	serv->error_callback = call_f;
}

void omg_serv_set_current_as_low(omg_serial_serv_t* serv, unsigned reset, uint16_t port_n) {
	if (!serv || port_n >= PORTS_N) return;
	uint16_t current_avg = 0;
	AVERAGE(serv->last_measures[port_n], current_avg);
	serv->current_lo[port_n] = reset ? current_avg : (current_avg + serv->current_lo[port_n]) / 2;
}

void omg_serv_set_current_as_high(omg_serial_serv_t* serv, unsigned reset, uint16_t port_n) {
	if (!serv || port_n >= PORTS_N) return;
	uint16_t current_avg = 0;
	AVERAGE(serv->last_measures[port_n], current_avg);
	serv->current_hi[port_n] = reset ? current_avg : (current_avg + serv->current_hi[port_n]) / 2;
}

static void omg_serv_handle_error(omg_serial_serv_t *serv, OMGERRSTAT state) {
	if (!serv) return;
	
	if (state != serv->current_error && serv->error_callback) {
		serv->current_error = state;
		serv->error_callback(state);
	}
	serv->current_error = state;
}

// 「Сколько будет стоить　залупливание видео?」-「В смысле  не понял? Loop - зациклить, вы английский не учили?」
static void omg_serv_server_looper(omg_serial_serv_t* serv) {
	using namespace std::chrono_literals;
	if (!serv) return;
	omg_serial_recv_t current_state = { 0, 0 };
	uint16_t io_buff[PORTS_N];
	while (serv->state) {
		unsigned i_to_w = serv->begin_ind;
		omg_serial_recv_t buffer_state = { 0, 0 };
		serv->begin_ind = (serv->begin_ind + 1) % KEEP_MEASURES;
		int have_read = serv->file_handler->readSerialPort(io_buff, sizeof(io_buff));

		if (have_read != sizeof(io_buff)) {
			omg_serv_handle_error(serv, serv->file_handler->isConnected() ? OMG_ERR_UNKNOWN : OMG_ERR_DISCNCT);
			continue;
		}

		for (unsigned i = 0; i < PORTS_N; i++) {
			serv->last_measures[i][i_to_w] = io_buff[i];
			buffer_state.port_bit |= io_buff[i] > serv->current_lo[i] ? 1 << i : 0; // возможно нужно лоу использовать вместо нуля
			buffer_state.statuses_bits |= io_buff[i] > serv->current_hi[i] ? 1 << i : 0;
		}

		if (serv->input_callback && (current_state.port_bit != buffer_state.port_bit || current_state.statuses_bits != buffer_state.statuses_bits)) {
			serv->input_callback(buffer_state);
		}
		current_state = buffer_state;

		std::this_thread::sleep_for(REFRESH_TIME);
	}

	omg_serv_handle_error(serv, OMG_ERR_STOP);
}

unsigned omg_serv_start(omg_serial_serv_t* serv) {
	if (!serv || serv->state) return 0;

	serv->state = 1;
	serv->thr_handler = new std::thread(omg_serv_server_looper, serv);

	return 1;
}

unsigned omg_serv_state(omg_serial_serv_t* serv) {
	return serv ? serv->state : 0;
}

unsigned omg_serv_send_stop(omg_serial_serv_t* serv) {
	if (serv && serv->thr_handler) { 
		serv->state = 0;
		return 1;
	}
	return 0;
}


#ifdef OMGDEVELOPEMENT_LOG
unsigned omg_serv_get_channels(omg_serial_serv_t* serv, uint16_t* chan1, uint16_t* chan2, uint16_t* chan3, uint16_t* chan4, uint16_t* chan5) {
	if (!serv) return 0;
	if (chan1) *chan1 = serv->last_measures[0][serv->begin_ind];
	if (chan2) *chan2 = serv->last_measures[1][serv->begin_ind];
	if (chan3) *chan3 = serv->last_measures[2][serv->begin_ind];
	if (chan4) *chan4 = serv->last_measures[3][serv->begin_ind];
	if (chan5) *chan5 = serv->last_measures[4][serv->begin_ind];
	return 1;
}
#endif