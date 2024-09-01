/*
 * Project_Name    :   PIR_Motion_Sensor_Interface
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LCD_Drive.h"
#include "UART.h"




int main (void) {

	char newline[4] = "\r\n";
	DDRA  = 0xFF;
	DDRC  = 0x00;
	DDRB  = 0xFF;	
	DDRB  = 0xFE;
	PORTB = 0xFE;
	PORTC = 0x00;
	DDRD  = (1 << PD1);
	
	LCD_Init();
	UART_Init();
	
	for (;;) {

		if ((PINC & (1 << PINC0))) {

			PORTA |= (1 << PORTA0);

			UART_Transmit_string(" Motion has been detected! ");
			UART_Transmit_string(newline);
			UART_Transmit_string(" LED ON ");
			UART_Transmit_string(newline);
			_delay_ms(10);

			LCD_Gotoxy(0,0);
			LCD_Write_String ("Motion detected!  ");
			LCD_Gotoxy(1,3);
			LCD_Write_String (" LED ON ");
			_delay_ms (1000);

		} else {

			PORTA &= ~(1 << PORTA0);
			UART_Transmit_string(" Motion has been stopped! ");
			UART_Transmit_string(newline);
			UART_Transmit_string(" LED OFF ");
			UART_Transmit_string(newline);
			_delay_ms(10);

			LCD_Gotoxy(0,0);
			LCD_Write_String ("Motion stopped!  ");
			LCD_Gotoxy(1,3);
			LCD_Write_String (" LED OFF ");
			_delay_ms (1000);
		}
	}
	
	return 0;
}





