/*
 * Project_Name    :   I2C_EEPROM
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LCD_Drive.h" 
#include "I2C_Master.h"
#include "EEPROM.h"



int main (void) {

	char array[] = "Akram";
	DDRB  = 0xFF;
	PORTB = 0xFF;	           
	
	LCD_Init();
	I2C_Master_Init();
	LCD_Gotoxy (0,2);
	LCD_Write_String (" EEPROM_M24C16 ");
	LCD_Gotoxy (1,0);
	LCD_Write_String ("EEPROM_R : ");
	LCD_Gotoxy (1,11);
	EEPROM_Write(0x00,array);
	EEPROM_Read (0x00,array);
	
	return 0;
}





