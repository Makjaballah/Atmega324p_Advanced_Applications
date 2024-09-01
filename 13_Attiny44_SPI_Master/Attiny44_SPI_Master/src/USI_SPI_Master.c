/*
 * File_Name       :   USI_SPI_Master.c
 * Author          :   Mohamed Akram JABALLAH
*/

 


#include <avr/io.h>	
#include <util/delay.h>	
#include "USI_SPI_Master.h"	


void USI_SPI_Init (void) {
	
	UNSET_CS;
	DDR_SPI &= ~ (1 << USI_DI );
	DDR_SPI |=   (1 << USI_DO) | (1 << USI_SCK) | (1 << USI_CS);
	USICR    =   (1 << USIWM0) | (1 << USICS1)  | (1 << USICLK); 
	USICR   &= ~ (1 << USISIE) | (1 << USIOIE)  | (1 << USIWM1);                                   
}


uint8_t USI_SPI_Transmit (uint8_t data) {
	
	USIDR = data;
	USISR = (1 << USIOIF);
	
	while((USISR & (1 << USIOIF)) == 0) {
		
		USICR = (1 << USIWM0) | (1 << USICS1) | (1 << USICLK) | (1 << USITC);
	}

	return USIDR;
}


  










 

 


