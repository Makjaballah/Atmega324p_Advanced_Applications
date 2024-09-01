/*
 * File_Name       :   DS18B20.h
 * Author          :   Mohamed Akram JABALLAH
*/


#ifndef DS18B20_H_
#define DS18B20_H_


#include <avr/io.h>
#include <util/delay.h>
#include "OneWire.h"

 


int8_t ds18b20_init(void);
int8_t ds18b20_start(void);
int16_t ds18b20_read_temperature(void);




#endif 







