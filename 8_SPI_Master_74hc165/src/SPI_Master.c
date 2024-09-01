/*
 * File_Name       :   SPI_Master.c
 * Author          :   Mohamed Akram JABALLAH
*/

 


#include <avr/io.h>	
#include <util/delay.h>	
#include "SPI_Master.h"	





void SPI_Master_Init (void) {
	
	DDRB |=  (1 << MOSI) | (1 << SCK) | (1 << SS);	
	DDRB &= ~(1 << MISO);						
	SS_Disable;
	SPCR0 = (1 << SPE0) | (1 << MSTR0) |  (1 << SPR00);	
}


void SPI_Master_Transmit (char SPI_Data) {
	
	SPDR0 = SPI_Data;			
	while(!(SPSR0 & (1 << SPIF0)));				
}


char SPI_Master_Receive (void) {

	while(!(SPSR0 & (1 << SPIF0)));	 
	return(SPDR0);			 
}













 

 


