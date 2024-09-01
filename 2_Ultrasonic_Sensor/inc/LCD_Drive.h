/*
 * File_Name       :   LCD_Drive.h
 * Author          :   Mohamed Akram JABALLAH
*/




#ifndef LCD_DRIVE_H_
#define LCD_DRIVE_H_



void LCD_Init (void); 
void Write_LCD_Command (unsigned char cmd); 
void Write_LCD_Data (unsigned char data);
void LCD_Gotoxy (unsigned char x, unsigned char y); 
void LCD_Write_String (char *str); 
void LCD_Clear (void);


#endif 








