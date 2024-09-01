/*
 * Project_Name    :   Attiny44_SPI_Master
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Attiny44
*/


#include <avr/io.h>
#include <util/delay.h>
#include "USI_SPI_Master.h"


int main(void) {

	char segment_val[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };
    char counter = 0;

    USI_SPI_Init();
    DDRA  &= ~(1 << DDA2);
    PORTA |=  (1 << PA2);

    SET_CS;
    USI_SPI_Transmit (segment_val[counter]);
    UNSET_CS;
    
    for (;;) {

    	if((PINA & (1 << PA2))){
    		counter += 1;
    		if(counter > 15) counter = 0;
    		SET_CS;
    		USI_SPI_Transmit (segment_val[counter]);
    		UNSET_CS;
    		_delay_ms (1000);
    	}
    }

    return 0;
}

