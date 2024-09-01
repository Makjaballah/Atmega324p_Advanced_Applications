/*
 * File_Name       :   USI_SPI_Master.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef  USI_SPI_Master_H_
#define  USI_SPI_Master_H_



#define PORT_SPI     PORTA
#define DDR_SPI      DDRA
#define USI_SCK      PA4
#define USI_DO       PA5
#define USI_DI       PA6
#define USI_CS       PA7

#define UNSET_CS     PORT_SPI |=  (1 << USI_CS)
#define SET_CS       PORT_SPI &= ~(1 << USI_CS)


void USI_SPI_Init (void);
uint8_t USI_SPI_Transmit (uint8_t data);



#endif 







