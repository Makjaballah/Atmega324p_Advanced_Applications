/*
 * Project_Name    :   LCD_I2C_Display
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include "LCD_I2C_Drive.h"


int main(void) {

	LCD_I2C_Init();
	LCD_I2C_clear();
	LCD_I2C_Write_String("Counter = ");
	_delay_ms(500);
	uint8_t counter = 0;
	
	for (;;) {

		LCD_I2C_moveCursor(0, 11);
		LCD_I2C_intgerToString(counter++);
		_delay_ms(500);
	}

	return 0;
}
