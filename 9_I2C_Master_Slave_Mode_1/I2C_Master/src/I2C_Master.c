/*
 * File_Name       :   I2C_Master.c
 * Author          :   Mohamed Akram JABALLAH
*/




#include <avr/io.h>
#include <util/delay.h>
#include "I2C_Master.h"


void I2C_Master_Init (void) {

	TWSR  = 0x00;
	TWBR  = 0x02;
	TWCR |= (1 << TWEN);
}


void I2C_Master_Start (void) {
												                             
	TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);		  
	while (!(TWCR & (1 << TWINT)));							
}


void  I2C_Master_Write (uint8_t data) {
	
	TWDR = data;				                            
	TWCR = (1 << TWEN) | (1 << TWINT);			             
	while (!(TWCR & (1 << TWINT)));							
}


uint8_t  I2C_Master_Read_Ack (void) {

	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);		
	while (!(TWCR & (1 << TWINT)));                        
	return  TWDR; 
}
	

uint8_t  I2C_Master_Read_NAck (void)	{

	TWCR = (1 << TWEN) | (1 << TWINT);		               
	while (!(TWCR & (1 << TWINT)));		                   
	return TWDR;			                               
}


void  I2C_Master_Stop (void) {

	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
	while(TWCR & (1 << TWSTO));		                      
}


uint8_t I2C_Master_getStatus (void) {

    uint8_t status;
    status = TWSR & 0xF8;
    return status;
}













 

 


