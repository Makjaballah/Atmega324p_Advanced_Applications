/*
 * Project_Name    :   LM35_ADC_Interfacing
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>



void ADC_Init (void);
unsigned int ADC_Read (unsigned char ADCpin);

int main(void) {

	float voltage;
	float temperature;
	int _temperature;
	char segment_val[16] = { 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71 };
	
	DDRC = 0xFF;
	DDRB = 0xFF;
	DDRA = 0x00;
	
	ADC_Init();
	
	for (;;) {
		
		voltage = (float)(ADC_Read(0))*5/1024;

		
		temperature  = voltage*100;
		temperature *= 10;
		_temperature = (int)temperature;
		
		
		PORTB = 0x00;
		PORTC = segment_val[_temperature/1000];
		if(_temperature >= 1000)	
		PORTB = 0x01;
		_delay_ms(10);
		
		PORTB = 0x00;
		PORTC = segment_val[(_temperature%1000)/100];
		PORTB = 0x02;
		_delay_ms(10);
		
		PORTB = 0x00;
		PORTC = segment_val[(_temperature%100)/10]|0x80;
		PORTB = 0x04;
		_delay_ms(10);
		
		PORTB = 0x00;
		PORTC = segment_val[_temperature%10];
		PORTB = 0x08;
		_delay_ms(10);
	}
	
	return 0;
}


void ADC_Init (void) {

	ADMUX  |= (1 << REFS0);
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}


unsigned int ADC_Read (unsigned char ADCpin) {

	ADCpin &= 0x07;
	ADMUX   = (ADMUX & 0xF8) | ADCpin ;
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));

	return ADC;
}





