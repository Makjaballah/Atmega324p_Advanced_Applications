/*
 * File_Name       :   LCD_Drive.c
 * Author          :   Mohamed Akram JABALLAH
*/




#include <util/delay.h>			
#include <avr/io.h>			          
#include "LCD_Drive_Setting.h"
#include "LCD_Drive.h"




void LCD_Init (void) {
	
	Write_LCD_Command (0x02);
	Write_LCD_Command (0x28);
	Write_LCD_Command (0x0C);
	Write_LCD_Command (0x06);
	Write_LCD_Command (0x01);

}


void Write_LCD_Command (unsigned char cmd) {

	LCD_Control_Port  = (LCD_Control_Port & 0x0F) | (cmd & 0xF0);
	LCD_Control_Port  &= ~ (1 << RS);
	LCD_Control_Port  |=   (1 << EN);
	_delay_us (2);
	LCD_Control_Port  &= ~ (1 << EN);
	
	_delay_us (200);

	LCD_Control_Port  = (LCD_Control_Port & 0x0F) | (cmd << 4);
	LCD_Control_Port  |=   (1 << EN);
	_delay_us (2);
	LCD_Control_Port  &= ~ (1 << EN);
	_delay_us (2);

}


void Write_LCD_Data (unsigned char data) {

	LCD_Data_Port    = (LCD_Data_Port  & 0x0F) | (data & 0xF0);
	LCD_Data_Port   |=   (1 << RS);
	LCD_Data_Port   |=   (1 << EN);
	_delay_us (2);
	LCD_Data_Port   &= ~ (1 << EN);
	
	_delay_us (200);

	LCD_Data_Port    = (LCD_Data_Port  & 0x0F) | (data << 4);
	LCD_Data_Port   |=   (1 << EN);
	_delay_us (2);
	LCD_Data_Port   &= ~ (1 << EN);
	_delay_us (2);

}


void LCD_Write_String (char *str) {

	int i;
	for (i = 0; str[i] != 0; i++) {

		Write_LCD_Data (str[i]);
	}
}


void LCD_Gotoxy (unsigned char x_pos, unsigned char y_pos) {

	uint8_t The_Address = 0;

	if (x_pos == 0)
		The_Address = 0x80;
	else if (x_pos == 1)
		The_Address = 0xC0;

	if (y_pos < 16)
		The_Address += y_pos;
	Write_LCD_Command (The_Address);
}


void LCD_Clear (void) {

	Write_LCD_Command (0x01);		
	Write_LCD_Command (0x80);		
}


