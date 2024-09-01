/*
 * File_Name       :   I2C_Slave.c
 * Author          :   Mohamed Akram JABALLAH
*/

 


#include <avr/io.h>
#include <util/delay.h>
#include "I2C_Slave.h"



void I2C_Slave_Init (uint8_t slave_address) {
	
	TWAR = slave_address;					                   
	TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);	                  
}


void I2C_Slave_Listen (void) {
	
	TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
	while (!(TWCR & (1 << TWINT)));                                               	
}


void I2C_Slave_Transmit (uint8_t data) {
	
	TWDR = data;				  	                           
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);		           
	while (!(TWCR & (1 << TWINT)));				                  
}


uint8_t I2C_Slave_Receive (void) {
	
	uint8_t recv_data; 
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	recv_data = TWDR;
	return TWDR; 																
}

void I2C_stop (void) {

	TWCR &= ~( (1 << TWEA) | (1 << TWEN));
}
































 

 


