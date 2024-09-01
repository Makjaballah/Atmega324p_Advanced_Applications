/*
 * Project_Name    :   USART_microcontroller_Transmitter
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define BAUDRATE 9600
#define MYUBRR F_CPU / 16 / BAUDRATE - 1


void UART_Init (void);

unsigned char data_out = 0;

ISR (USART0_UDRE_vect ) {

	UDR0 = data_out;
}


int main (void) {

	DDRD  = 0x06;
	PORTD = 0xF8;
	
	UART_Init();

	for (;;) {
		
		data_out = (PIND >> 3) & 0x1F;
		_delay_ms (20);
	}

	return 0;
}

void UART_Init (void) {

	UCSR0B = (1 << TXEN0)  | (1 << UDRIE0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0H = (unsigned char) (MYUBRR >> 8);
	UBRR0L = (unsigned char)  MYUBRR;
	sei ();
}


