/*
 * Project_Name    :   I2C_Slave
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "LCD_Drive.h"
#include "I2C_Slave.h"

#define Slave_Address			0x20



int main(void) {

	uint8_t cnt = 0;
    char    buffer[10];
    
    DDRA  = 0xFF;
    
    LCD_Init();
    I2C_Slave_Init(Slave_Address);

    
    LCD_Gotoxy(0,6);
    LCD_Write_String (" Slave Chip ");
    LCD_Gotoxy(1,0);
    LCD_Write_String ("Receive_Data:    ");
    
    for (;;) {

    	I2C_Slave_Listen();
    	cnt = I2C_Slave_Receive();
    	sprintf(buffer, "%d    ", cnt);
    	LCD_Gotoxy(1,14);
    	LCD_Write_String (buffer);
    }
    
    return 0;
}

