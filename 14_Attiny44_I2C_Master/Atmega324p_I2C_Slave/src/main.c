/*
 * Project_Name    :   Atmega324p_I2C_Slave
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>								
#include <util/delay.h>							
#include <stdio.h>								
#include <string.h>								
#include "I2C_Slave.h"
					
#define Slave_Address			0x20



int main(void) {

	DDRB = 0xFF;
	I2C_Slave_Init(Slave_Address);

	for (;;) {

		I2C_Slave_Listen();
		PORTB = I2C_Slave_Receive();
		I2C_stop();
	}

	return 0;
}












