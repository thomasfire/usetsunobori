// omg_serv.cpp : Defines the entry point for the application.
//

#include "omg_serv.h"

#include "SerialPort.h"

#include <stdio.h>
#include <thread>

struct omg_serial_serv_t{
	SerialPort* file_handler;
	omg_serial_input_callback_f input_callback;
	std::thread* thr_handler;
	unsigned state;
};
