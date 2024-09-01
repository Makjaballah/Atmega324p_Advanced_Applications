/*
 * File_Name       :   OneWire.c
 * Author          :   Mohamed Akram JABALLAH
*/

 

#include <avr/io.h>
#include <util/delay.h>			           
#include "OneWire.h"




uint8_t OneWire_reset (void) {

	uint8_t i;
	OneWire_LOW();
	OneWire_OUTPUT_MODE();
	_delay_us (480);
	OneWire_INPUT_MODE();
	_delay_us (100);
	i = (OneWire_PIN & (1 << OneWire_DQ));
	_delay_us (420);
	return i;
}


void OneWire_write_bit (uint8_t bit) {

	OneWire_LOW();
	OneWire_OUTPUT_MODE();
	_delay_us (2);

	if(bit) OneWire_INPUT_MODE();
	_delay_us (80);
	OneWire_INPUT_MODE();
	_delay_us (2);
}


void OneWire_write_byte (uint8_t byte) {

	uint8_t i = 8;
	while(i--) {

		OneWire_write_bit(byte&1);
		byte >>= 1;
	}
}



uint8_t OneWire_read_bit (void) {

	uint8_t bit = 0;
	OneWire_LOW();
	OneWire_OUTPUT_MODE();
	_delay_us (2);
	OneWire_INPUT_MODE();
	_delay_us (5);
	if(OneWire_PIN & (1 << OneWire_DQ)) bit = 1;
	_delay_us (55);
	return bit;
}


uint8_t OneWire_read_byte (void) {

	uint8_t i = 8, n = 0;
	while(i--) {
		n >>= 1;
		n |= (OneWire_read_bit() << 7);
	}

	return n;
}






























 

 


