/*
 * File_Name       :   I2C_Slave.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef I2C_Slave_H_
#define I2C_Slave_H_



void I2C_Slave_Init (uint8_t slave_address);		
void I2C_Slave_Listen (void);			       
void I2C_Slave_Transmit (uint8_t  data);		
uint8_t I2C_Slave_Receive (void);			
void I2C_stop (void);


#endif 







