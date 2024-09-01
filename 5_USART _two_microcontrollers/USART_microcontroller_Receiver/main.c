/*
 * Project_Name    :   USART_microcontroller_Receiver
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <avr/interrupt.h>


#define BAUDRATE 9600
#define MYUBRR F_CPU / 16 / BAUDRATE - 1



#define EN  PB0
#define RS  PB1


void LCD_Init (void);
void Write_LCD_Command(unsigned char cmd);
void Write_LCD_Data (unsigned char data);
void LCD_Write_String (char *str);
void LCD_Gotoxy (unsigned char x, unsigned char y);

void UART_Init (void);
unsigned  data_in;

ISR (USART0_RX_vect) {

	data_in = UDR0;
}



int main (void) {

	char Temp [15];
	DDRC  = 0xFF;
	DDRB  = 0xFF;

	UART_Init();
	LCD_Init();

	for (;;) {
		
		sprintf (Temp, "Value: %.2d", data_in);
		LCD_Gotoxy (0,0);
		LCD_Write_String (Temp);
		PORTC = data_in;
	}

	return 0;
}


void UART_Init (void) {

	UCSR0B |= (1 << RXEN0)  | (1 << RXCIE0);
	UCSR0C  = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0H  = (unsigned char) (MYUBRR >> 8);
	UBRR0L  = (unsigned char) MYUBRR;
	sei ();
}


void LCD_Init (void) {

	Write_LCD_Command (0x02);
	Write_LCD_Command (0x28);
	Write_LCD_Command (0x0C);
	Write_LCD_Command (0x06);
	Write_LCD_Command (0x01);
}

void Write_LCD_Command (unsigned char cmd) {

	PORTB   = (PORTB & 0x0F) | (cmd & 0xF0);
	PORTB  &= ~(1 << RS);
	PORTB  |=  (1 << EN);
	_delay_us (2);
	PORTB  &= ~(1 << EN);

	PORTB   = (PORTB & 0x0F) | (cmd << 4);
	PORTB  |= (1 << EN);
	_delay_us (2);
	PORTB  &= ~ (1 << EN);
	_delay_us (2);
}

void Write_LCD_Data (unsigned char data) {

	PORTB   =  (PORTB & 0x0F) | (data & 0xF0);
	PORTB  |=  (1 << RS);
	PORTB  |=  (1 << EN);
	_delay_us (2);
	PORTB  &= ~(1 << EN);

	PORTB   =  (PORTB & 0x0F) | (data << 4);
	PORTB  |=  (1 << EN);
	_delay_us (2);
	PORTB  &= ~(1 << EN);
	_delay_us (2);
}


void LCD_Write_String (char *str) {

	int i;
	for (i = 0; str[i] != 0; i++) {

		Write_LCD_Data (str[i]);
	}
}


void LCD_Gotoxy (unsigned char x, unsigned char y) {

	if (y == 0)
		Write_LCD_Command (0x80 + x);
	if (y == 1)
		Write_LCD_Command (0xC0 + x);
}






