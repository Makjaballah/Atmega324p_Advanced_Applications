/*
 * Project_Name    :   Ultrasonic_Sensor
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/
 
 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include "LCD_Drive.h"
#include "UART.h"



volatile uint16_t capt_1, capt_2;
volatile uint8_t  mask = 0;
volatile uint16_t Timer_Overflow;
volatile uint16_t Timer_Overflow_Final;

ISR(TIMER1_OVF_vect) {

	Timer_Overflow ++;
}

ISR(TIMER1_CAPT_vect) {

	if(mask == 0) {

		capt_1 = ICR1;
		TCCR1B &= ~(1 << ICES1);
		Timer_Overflow = 0;

	} else if(mask == 1) {

		capt_2  = ICR1;
		Timer_Overflow_Final = Timer_Overflow;
		TIMSK1 &= ~((1 << ICIE1) | (1 << TOIE1));
	}

	mask ++;
}



int main(void) {
	
	unsigned long cnt;
	double distance;
	char string[10];
	char d[10] = "";
	char a[30] = "Distance = ";
	char b[30] = " cm ";
	char newline[20] = "\r\n";
	
	DDRB  = 0xFF;
	DDRD |=  (1 << DDD5);
	DDRD &= ~(1 << DDD6);
	
	UART_Init();
	LCD_Init();
	LCD_Gotoxy (0,0);
	LCD_Write_String("HC-SR04 Sensor");
	_delay_ms (10);	
	
	cli();
	TCCR1A  = 0x00;
	TCCR1B  = 0x00;
	TCNT1   = 0x00;
	TCCR1B |= (1 << ICES1) | (1 << CS10);
	TIMSK1 |= (1 << ICIE1) | (1 << TOIE1);
	sei();
	
	for (;;) {

		PORTD |=  (1 << PORTD5);
		_delay_us(10);
		PORTD &= ~(1 << PORTD5);
		
		if(mask == 2) {

			mask = 0;
			cnt = ((unsigned long)capt_2 + (unsigned long)(Timer_Overflow_Final * 65536))-(unsigned long)capt_1;
			distance = (double)(cnt / 466.47);
			
			UART_Transmit_string(a);
			dtostrf(distance,6,2,d);
			UART_Transmit_string(d);
			UART_Transmit_string(b);
			UART_Transmit_string(newline);
			_delay_ms(10);
			
			dtostrf(distance,2,2,string);
			strcat(string," cm  ");
			LCD_Gotoxy (1, 0);
			LCD_Write_String("Dist =  ");
			LCD_Gotoxy (1, 7);
			LCD_Write_String(string);
			_delay_ms(350);

			Timer_Overflow_Final = 0; Timer_Overflow = 0;
			TCCR1B |= (1 << ICES1);
			TIFR1  |= (1 << ICF1)  | (1 << TOIE1);
			TIMSK1 |= (1 << ICIE1) | (1 << TOIE1);
		}
	}

	return 0;
}




