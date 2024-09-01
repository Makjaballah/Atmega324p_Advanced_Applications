/*
 * Project_Name    :   I2C_Slave
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

	DDRA = 0xFF;
	I2C_Slave_Init(Slave_Address);

	for (;;) {

		I2C_Slave_Listen();
		PORTA = I2C_Slave_Receive();
	}

	return 0;
}












