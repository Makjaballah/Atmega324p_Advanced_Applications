/*
 * File_Name       :   I2C_Master.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_



void I2C_Master_Init (void);	                            
void I2C_Master_Start (void);			             
void I2C_Master_Stop (void);                                 
void I2C_Master_Write (uint8_t data);                        
uint8_t I2C_Master_Read_Ack (void);                          
uint8_t I2C_Master_Read_NAck (void);	                    
uint8_t I2C_Master_getStatus (void);


#endif 




