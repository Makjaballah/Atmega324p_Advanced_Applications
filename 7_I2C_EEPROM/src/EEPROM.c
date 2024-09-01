/*
 * File_Name       :   EEPROM.c
 * Author          :   Mohamed Akram JABALLAH
*/




#include <avr/io.h>
#include <util/delay.h>
#include <string.h>		           
#include "I2C_Master.h"
#include "LCD_Drive.h"
#include "EEPROM.h"



void EEPROM_Write(uint8_t Address,uint8_t *ptr) {

	I2C_Master_Start();
	I2C_Master_Write(EEPROM_Write_Addess);
	I2C_Master_Write(Address);
	for (int i = 0; i < strlen(ptr); i++) {
		I2C_Master_Write(ptr[i]);
	}
	I2C_Master_Stop();
	_delay_ms(10);
}


void EEPROM_Read(uint8_t Address,uint8_t* ptr) {

	I2C_Master_Start();
	I2C_Master_Write(EEPROM_Write_Addess);
	I2C_Master_Write(Address);		
	I2C_Master_Start();
	I2C_Master_Write(EEPROM_Read_Addess);
	for (int i = 0; i < strlen(ptr); i++) {
		Write_LCD_Data(I2C_Master_Read_Ack());
	}
	I2C_Master_Stop();			
}








