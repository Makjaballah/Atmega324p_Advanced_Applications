/*
 * Project_Name    :   DS18B20_Interfacing
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
#include "DS18B20.h" 
#include "OneWire.h"
#include "UART.h"




int main (void) {
	
	float temperature;
	char buffer [50];
	char t[10] = "";
	char a[16] = "Temperature = ";
	char b[16] = " \xB0""C ";
	char newline[4] = "\r\n";

	DDRB  = 0xFE;
	PORTB = 0xFE;
	DDRD  = (1 << PD1);
	
	LCD_Init();
	UART_Init();
	ds18b20_init();
	
	for (;;) {

		ds18b20_start();
		temperature = (float)(ds18b20_read_temperature())/16;
		UART_Transmit_string(a);
		dtostrf(temperature,6,2,t);
		UART_Transmit_string(t);
		UART_Transmit_string(b);
		UART_Transmit_string(newline);

		LCD_Gotoxy(0,0);
		LCD_Write_String ("TEMP =  ");
		LCD_Gotoxy(0,6);
		dtostrf(temperature , 3, 2, buffer);
		LCD_Write_String (buffer);
		LCD_Gotoxy(0,12);
		LCD_Write_String (" \337C   ");
		_delay_ms (1000);
	}
	
	return 0;
}





