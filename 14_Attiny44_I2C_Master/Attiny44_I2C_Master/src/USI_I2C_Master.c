/*
 * File_Name       :   USI_I2C_Master.c
 * Author          :   Mohamed Akram JABALLAH
*/




#include <avr/io.h>
#include <util/delay.h>
#include "USI_I2C_Master.h"



void USI_I2C_Master_Init (void) {
	
	DDR_USI |= (1 << PIN_USI_SDA);
	DDR_USI |= (1 << PIN_USI_SCL);

	PORT_USI |= (1 << PIN_USI_SCL);
	PORT_USI |= (1 << PIN_USI_SDA);

	USIDR = 0xFF;
	USICR = (1 << USIWM1) | (1 << USICS1) | (1 << USICLK);
	USISR = (1 << USISIF) | (1 << USIOIF) | (1 << USIPF) | (1 << USIDC) | (0x0 << USICNT0); 
}


void USI_I2C_Master_Start (void) {

	PORT_USI |= (1 << PIN_USI_SDA); 
	PORT_USI |= (1 << PIN_USI_SCL); 
	while (!(PORT_USI & (1 << PIN_USI_SCL)));

	PORT_USI &= ~(1 << PIN_USI_SDA); 

	_delay_us(WAIT_LONG);

	PORT_USI &= ~(1 << PIN_USI_SCL); 
	PORT_USI |=  (1 << PIN_USI_SDA); 
}


void USI_I2C_Master_Stop (void) {

	PORT_USI &= ~(1 << PIN_USI_SDA);
	PORT_USI |=  (1 << PIN_USI_SCL);
	while (! (PIN_USI & (1 << PIN_USI_SCL)));
	_delay_us(WAIT_LONG);
	PORT_USI |= (1 << PIN_USI_SDA);
	_delay_us(WAIT_SHORT);
}

unsigned char USI_I2C_Master_Transfer (unsigned char usisr_mask) {

	PORT_USI &= ~(1 << PIN_USI_SCL);
	USISR = usisr_mask;
	
	do {

		_delay_us(WAIT_LONG);
		USICR |= (1 << USITC);
		while (! (PIN_USI & (1 << PIN_USI_SCL)));
		_delay_us(WAIT_SHORT);
		USICR |= (1 << USITC);
	} while (!(USISR & (1 << USIOIF)));

	_delay_us(WAIT_LONG);
	unsigned char temp = USIDR;
	USIDR = 0xFF; 

	return temp; 
}


unsigned char USI_I2C_Master_Write_Byte (unsigned char data) {

	USIDR = data;
	USI_I2C_Master_Transfer(USISR_CLOCK_8_BITS);
	PORT_USI &= ~(1 << PIN_USI_SDA); 
	unsigned char nack = USI_I2C_Master_Transfer(USISR_CLOCK_1_BIT);
	PORT_USI |= (1 << PIN_USI_SDA);
	return nack;
}


unsigned char USI_I2C_Master_Read_Byte (unsigned char nack) {

	PORT_USI &= ~(1 << PIN_USI_SDA); 
	unsigned char data = USI_I2C_Master_Transfer(USISR_CLOCK_8_BITS);
	PORT_USI |= (1 << PIN_USI_SDA);
	USIDR = nack;
	USI_I2C_Master_Transfer(USISR_CLOCK_1_BIT);
	return data;
}




































