/*
 * File_Name       :   UART.c
 * Author          :   Mohamed Akram JABALLAH
*/




#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"



void UART_Init (void) {
	
	UCSR0B = (1 << TXEN0)  | (1 << RXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0H = (unsigned char) (MYUBRR >> 8);
	UBRR0L = (unsigned char) MYUBRR;
}


uint8_t UART_Receive (void) {

	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

 
void UART_Transmit (uint8_t data) {

	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}


void UART_Transmit_string (char *str) {

	unsigned char i = 0 ;
	 while(str[i] != 0) {
	     UART_Transmit(str[i]) ; 
		 i++;
	}
}









