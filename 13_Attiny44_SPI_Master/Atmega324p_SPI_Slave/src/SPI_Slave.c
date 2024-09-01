/*
 * File_Name       :   SPI_Slave.c
 * Author          :   Mohamed Akram JABALLAH
*/

 


#include <avr/io.h>	
#include <util/delay.h>	
#include "SPI_Slave.h"	


void SPI_Slave_Init (void) {
	
	DDRB &= ~((1 << MOSI) | (1 << SCK) | (1 << SS));   
	DDRB |=  (1 << MISO);			 
	SPCR0 =  (1 << SPE0);			 
}


void SPI_Slave_Transmit (char SPI_Data) {
	
	SPDR0 = SPI_Data;			
	while(!(SPSR0 & (1 << SPIF0)));				
	
}


char SPI_Slave_Receive (void) {

	while(!(SPSR0 & (1 << SPIF0)));	 
	return(SPDR0);			 
}













 

 


