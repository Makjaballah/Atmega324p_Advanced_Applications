/*
 * Project_Name    :   SPI_Master
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>	
#include <util/delay.h>	
#include <stdio.h>	
#include <string.h>	
#include "LCD_Drive.h"
#include "SPI_Master.h"


int main(void) {

	uint8_t cnt;
	char    buffer[10];
	DDRA  = 0xFF;
	 
	
	LCD_Init();
	SPI_Master_Init();
	
	LCD_Gotoxy(0,6);
	LCD_Write_String (" Master Chip");
	LCD_Gotoxy(1,0);
	LCD_Write_String ("Sending_Data:    ");
	SS_Enable;
	cnt = 0;
	
	for (;;) {

		SPI_Master_Transmit(cnt);
		sprintf(buffer, "%d   ", cnt);
		LCD_Gotoxy(1,14);
		LCD_Write_String (buffer);
		cnt++;
		if (cnt > 25)
			cnt = 0;
		_delay_ms(500);
	}
	
	return 0;
}

