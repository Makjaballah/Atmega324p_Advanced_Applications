/*
 * Project_Name    :   SPI_Master_74HC165
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include "SPI_Master.h"
#include "UART.h"



int main(void) {
	
	uint8_t val;
	int i;
	char buf[5];
	DDRD = (1 << PD1);
	UART_Init();
	SPI_Master_Init();

	for (;;) {
		
		PORTB  = (1 << PORTB4);
		SPI_Master_Transmit(0x00);
		PORTB &= ~ (1 << PORTB4);
		val = SPI_Master_Receive();
		_delay_ms(10);
		UART_Transmit_string ("\n\r");
		
		for(i = 0; i < 4; i++) {
			UART_Transmit_string ("\n\rDIP");
			buf[0] = i + '0';
			buf[1] = ' ';
			buf[2] = 0;
			UART_Transmit_string (buf);
			if((val & (1 << i)) > 0)
				UART_Transmit_string ("1");
			else
				UART_Transmit_string ("0");
		}
		_delay_ms(2000);			
    }

	return 0;
}

