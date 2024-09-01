/*
 * Project_Name    :   SPI_Slave
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "LCD_Drive.h"
#include "SPI_Slave.h"



int main(void) {

	uint8_t cnt;
    char    buffer[10];
    
    DDRA  = 0xFF;
    
    LCD_Init();
    SPI_Slave_Init();
    
    LCD_Gotoxy(0,6);
    LCD_Write_String (" Slave Chip ");
    LCD_Gotoxy(1,0);
    LCD_Write_String ("Receive_Data:    ");
    
    for (;;) {

    	cnt = SPI_Slave_Receive();
	sprintf(buffer, "%d   ", cnt);
	LCD_Gotoxy(1,14);
	LCD_Write_String (buffer);
    }
    
    return 0;
}

