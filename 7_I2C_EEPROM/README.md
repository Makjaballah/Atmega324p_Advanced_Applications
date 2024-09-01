# Project:  M24C16 I2C Serial EEPROM Interfacing with Atmega324p Microcontroller

## The aim
EEPROM is Electrically Erasable Programmable Read-Only Memory. It is non-volatile type of memory as it holds the data even when power is off. The aim of this application is to write an array block "Akram" in the M24C16 I2C Serial EEPROM at address 0x00, and reading it back from the same memory. After reading it is also printed on an 16x2 LCD display for testing. The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. The system is designed and simulated using Proteus Simulation Software.

## Hardware Requirements

```
      1- Atmega324p microcontroller
      2- 16x2 LCD display
      3- M24C16: 16-Kbit serial I2C bus EEPROM
      4- Proteus Debuggers and Virtual Instruments Mode (I2C)
```
## Drivers

```
      1_MCAL
          -> I2C_Master
      2_HAL
          -> LCD_Drive
          -> EEPROM
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/fad997e7-79e0-4737-b3a3-4fb5c05f6ad1" width="800">
