/*
 * File_Name       :   LCD_I2C_Drive.c
 * Author          :   Mohamed Akram JABALLAH
*/




#include <avr/io.h>
#include <util/delay.h>
#include "I2C_Master.h"
#include "LCD_I2C_Drive.h"

unsigned char lcd = 0x00;						               



void PCF8574_write (unsigned char data) {
	
	I2C_Master_Start();							        
	I2C_Master_Write((PCF8574 << 1) | WRITE);	                               
	I2C_Master_Write(data);						                
	I2C_Master_Stop();								
}


void LCD_I2C_Init (void) {	
	
	lcd = 0x04;						                        
	PCF8574_write(lcd);
	_delay_us(25);
	LCD_I2C_Write_Command(0x02);				                        
	LCD_I2C_Write_Command(0x28);				                      
	LCD_I2C_Write_Command(0x0F);				                        
	LCD_I2C_Write_Command(0x01);				                       
	LCD_I2C_Write_Command(0x06);				                       
	LCD_I2C_clear ();				                                
	LCD_I2C_Write_Command(0x80);				                        
}


void LCD_I2C_4bit_send (unsigned char data) {
	
	unsigned char temp = 0x00;					               
	
	lcd &= 0x0F;								       
	temp = (data & 0xF0);							     
	lcd |= temp;								       
	lcd |= (0x04);								       
	PCF8574_write(lcd);							       
	_delay_us(1);								      
	lcd &= ~(0x04);								      
	PCF8574_write(lcd);							       
	_delay_us(5);								       
	
	
	temp = ((data & 0x0F) << 4);						       
	lcd &= 0x0F;								        					
	lcd |= temp;								      
	lcd |= (0x04);							 	      
	PCF8574_write(lcd);							       
	_delay_us(1);								       
	lcd &= ~(0x04);								       
	PCF8574_write(lcd);							       
	_delay_us(5);								       
}


void LCD_I2C_Write_Command (unsigned char cmd) {
	
	lcd = 0x08;								       
	lcd &= ~(0x01);								      
	PCF8574_write(lcd);							       
	LCD_I2C_4bit_send(cmd);						               	
}


void LCD_I2C_Write_Data (unsigned char data) {
	
	lcd |= 0x09;								     
	PCF8574_write(lcd);							      
	LCD_I2C_4bit_send(data);						     
}


void LCD_I2C_Write_String (char *str) {
	
	while (*str != '\0')							      
	LCD_I2C_Write_Data(*str++);
}


void LCD_I2C_moveCursor (uint8_t row,uint8_t col) {

	uint8_t lcd_memory_address;
	switch(row)
	{
		case 0:
			lcd_memory_address = col;
				break;
		case 1:
			lcd_memory_address = col + 0x40;
				break;
		case 2:
			lcd_memory_address = col + 0x10;
				break;
		case 3:
			lcd_memory_address = col + 0x50;
				break;
	}					
	
	LCD_I2C_Write_Command(lcd_memory_address | 0X80);
}


void LCD_I2C_intgerToString (int data) {

	char buff[16];
	itoa(data,buff,10);
	LCD_I2C_Write_String(buff);
}


void LCD_I2C_clear (void) {
	
	LCD_I2C_Write_Command(0x01);
}


