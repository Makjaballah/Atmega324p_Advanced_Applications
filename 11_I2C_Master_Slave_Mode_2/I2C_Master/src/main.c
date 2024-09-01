/*
 * Project_Name    :   I2C_Master
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>	
#include <util/delay.h>	
#include <stdio.h>	
#include <string.h>	
#include "LCD_Drive.h"
#include "I2C_Master.h"


#define Slave_Write_Address		0x20
#define Slave_Read_Address		0x21


int main(void) {

	uint8_t cnt = 0;
	char    buffer[10];
	DDRA  = 0xFF;
	 
	
	LCD_Init();
	I2C_Master_Init();
	
	LCD_Gotoxy(0,6);
	LCD_Write_String (" Master Chip");
	LCD_Gotoxy(1,0);
	LCD_Write_String ("Sending_Data:    ");
	
	for (;;) {

		I2C_Master_Start();
		I2C_Master_Write (Slave_Write_Address);
		I2C_Master_Write (cnt);
		sprintf(buffer, "%d   ", cnt);
		LCD_Gotoxy(1,14);
		LCD_Write_String (buffer);
		cnt++;

		if (cnt > 25)
			cnt = 0;
		I2C_Master_Stop();
		_delay_ms(500);
	}
	
	return 0;
}

