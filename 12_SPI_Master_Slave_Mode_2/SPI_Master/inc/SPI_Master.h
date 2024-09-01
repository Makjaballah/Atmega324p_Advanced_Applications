/*
 * File_Name       :   SPI_Master.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef SPI_MASTER_H_
#define SPI_MASTER_H_



#define MOSI                  DDB5
#define MISO                  DDB6
#define SCK                   DDB7
#define SS                    DDB4
#define SS_Enable             PORTB  &= ~(1 << PORTB4)
#define SS_Disable            PORTB  |=  (1 << PORTB4)


void SPI_Master_Init (void);
void SPI_Master_Transmit (char SPI_Data);
char SPI_Master_Receive (void);




#endif 







