/*
 * Project_Name    :   I2C_Master
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>							
#include <util/delay.h>						
#include <stdio.h>							
#include <string.h>
#include "I2C_Master.h"							
				

#define Slave_Write_Address		0x20
#define Slave_Read_Address		0x21






int main(void) {

	unsigned char segment_val[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };
    char counter = 0;
    
   
    DDRC  &= ~(1 << DDC2);
    PORTC |=  (1 << PC2);
    
    I2C_Master_Init ();
    I2C_Master_Start();
    I2C_Master_Write (Slave_Write_Address);
    I2C_Master_Write (segment_val[counter]);
    I2C_Master_Stop();

    for (;;) {
    	if((PINC & (1 << PC2)) == 0) {
    		while((PINC & (1 << PC2)) == 0);
    		counter += 1;
    		if(counter > 15) counter = 0;

    		I2C_Master_Start();
    		I2C_Master_Write (Slave_Write_Address);
    		I2C_Master_Write (segment_val[counter]);
    		I2C_Master_Stop();
    	}
    }
    
    return 0;
}









