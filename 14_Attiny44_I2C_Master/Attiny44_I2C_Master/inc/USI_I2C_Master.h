/*
 * File_Name       :   USI_I2C_Master.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef  USI_I2C_Master_H_
#define  USI_I2C_Master_H_




#define   DDR_USI                       DDRA
#define   PORT_USI                      PORTA
#define   PIN_USI                       PINA
#define   PORT_USI_SDA                  PORTA6
#define   PORT_USI_SCL                  PORTA4
#define   PIN_USI_SDA                   PINA6
#define   PIN_USI_SCL                   PINA4
#define   WAIT_LONG	                    5
#define   WAIT_SHORT 	                4


#define USISR_CLOCK_8_BITS		        0xF0
#define USISR_CLOCK_1_BIT  		        0xFE




void USI_I2C_Master_Init (void);
void USI_I2C_Master_Start (void);
void USI_I2C_Master_Stop (void);
unsigned char USI_I2C_Master_Transfer (unsigned char usisr_mask);
unsigned char USI_I2C_Master_Write_Byte (unsigned char data);
unsigned char USI_I2C_Master_Read_Byte (unsigned char nack);




#endif 




