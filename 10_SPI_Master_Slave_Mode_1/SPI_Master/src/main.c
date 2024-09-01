/*
 * Project_Name    :   SPI_Master
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include "SPI_Master.h"





int main(void) {

	unsigned char segment_val[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };
    char counter = 0;
    SPI_Master_Init();
    DDRC  &= ~(1 << DDC2);
    PORTC |=  (1 << PC2);
    SS_Enable;
    SPI_Master_Transmit(segment_val[counter]);
    SS_Disable;

    for (;;) {

    	if((PINC & (1 << PC2)) == 0) {
    		while((PINC & (1 << PC2)) == 0);
    		counter += 1;
    		if(counter > 15) counter = 0;
    		SS_Enable;
    		SPI_Master_Transmit(segment_val[counter]);
    		SS_Disable;
    	}
    }
    
    return 0;
}









