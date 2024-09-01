/*
 * Project_Name    :   SPI_Slave
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include "SPI_Slave.h"


int main(void) {

	DDRA = 0xFF;
	SPI_Slave_Init();

	for (;;) {

		PORTA = SPI_Slave_Receive();
	}

	return 0;
}












