#pragma once

#include <stdint.h>

#define OMGDEVELOPEMENT_LOG 1

typedef enum {
	OMG_PORT_0 = 1 << 0,
	OMG_PORT_1 = 1 << 1,
	OMG_PORT_2 = 1 << 2,
	OMG_PORT_3 = 1 << 3,
	OMG_PORT_4 = 1 << 4,
} omg_port_e;


typedef enum {
	OMG_ERR_OK = 0,
	OMG_ERR_UNKNOWN = 1,
	OMG_ERR_DISCNCT = 2, // disconnect
	OMG_ERR_STOP = 3 // server is stopped
} OMGERRSTAT;

typedef struct {
	uint16_t port_bit;
	uint16_t statuses_bits;
} omg_serial_recv_t;

typedef void (*omg_serial_input_callback_f)(omg_serial_recv_t);
typedef void (*omg_serial_error_callback_f)(OMGERRSTAT);

struct omg_serial_serv_t;

omg_serial_serv_t *omg_serv_new(const char* portname);
void omg_serv_free(omg_serial_serv_t* serv);
void omg_serv_set_input(omg_serial_serv_t* serv, omg_serial_input_callback_f call_f);
void omg_serv_set_error(omg_serial_serv_t* serv, omg_serial_error_callback_f call_f);
void omg_serv_set_current_as_low(omg_serial_serv_t* serv, unsigned reset, uint16_t port_n); // reset - 1 - поставить текущее значение в качестве порога
void omg_serv_set_current_as_high(omg_serial_serv_t* serv, unsigned reset, uint16_t port_n); // 0 - усреднить по формуле новый_порог = (текущее + старый_порог)/2
unsigned omg_serv_start(omg_serial_serv_t* serv);
unsigned omg_serv_state(omg_serial_serv_t* serv);
unsigned omg_serv_send_stop(omg_serial_serv_t* serv);

#ifdef OMGDEVELOPEMENT_LOG
unsigned omg_serv_get_channels(omg_serial_serv_t* serv, uint16_t *chan1, uint16_t *chan2, uint16_t *chan3, uint16_t *chan4, uint16_t *chan5);
#endif

