/*
 * File_Name       :   UART.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef UART_H_
#define UART_H_


#include <avr/io.h>
#include <util/delay.h>


#define BAUDRATE 4800
#define MYUBRR ((F_CPU / 16 / BAUDRATE) - 1)




void UART_Init (void);
void UART_Transmit (uint8_t data);
uint8_t UART_Receive (void);
void UART_Transmit_string (char *str);


 


#endif 
