/*
 * File_Name       :   LCD_I2C_Drive.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef LCD_I2C_DRIVE_H_
#define LCD_I2C_DRIVE_H_


#define    PCF8574	                   0x20    
#define	   WRITE			              0
#define    READ			                  1



void PCF8574_write (unsigned char data);
void LCD_I2C_Init (void) ;
void LCD_I2C_4bit_send (unsigned char data);
void LCD_I2C_Write_Command (unsigned char cmd);
void LCD_I2C_Write_Data (unsigned char data);
void LCD_I2C_moveCursor (uint8_t row, uint8_t col);
void LCD_I2C_Write_String (char *str);
void LCD_I2C_intgerToString (int data);
void LCD_I2C_clear (void);


#endif /








