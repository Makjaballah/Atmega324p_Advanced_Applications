/*
 * File_Name       :   EEPROM.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef EEPROM_H_
#define EEPROM_H_



#define EEPROM_Write_Addess		0xA0 
#define EEPROM_Read_Addess		0xA1 


void EEPROM_Read (uint8_t Address,uint8_t *ptr);
void EEPROM_Write (uint8_t Address,uint8_t *ptr);



#endif 







