/*
 * File_Name       :   DS18B20.c
 * Author          :   Mohamed Akram JABALLAH
*/




#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>			           
#include "DS18B20.h"
#include "OneWire.h"



int8_t ds18b20_init (void) {

	OneWire_reset();
	return OneWire_reset();
}


int8_t ds18b20_start (void) {

	if (OneWire_reset()) return 1;
	OneWire_write_byte(OneWire_CMD_SKIPROM);
	OneWire_write_byte(OneWire_CMD_CONVERTTEMP);

	return 0;
} 


int16_t ds18b20_read_temperature (void) {

	int16_t temperature;
	while (OneWire_read_byte() == 0);

	OneWire_reset();
	OneWire_write_byte(OneWire_CMD_SKIPROM);
	OneWire_write_byte(OneWire_CMD_RSCRATCHPAD);

	temperature  =  OneWire_read_byte();
	temperature |= OneWire_read_byte() << 8;
	OneWire_reset();

	return temperature;
}








