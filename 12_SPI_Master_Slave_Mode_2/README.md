# Project: SPI communication using two Atmega324p Microcontrollers

## The aim
The Serial Peripheral Interface (SPI) is a bus interface connection protocol originally started by Motorola Corp. It uses four pins for communication:
```
-> SDI (Serial Data Input)
-> SDO (Serial Data Output)
-> SCLK (Serial Clock)
-> CS (Chip Select)
```
ATmega324p microcontroller has an in-built SPI module. It can act as a master and slave SPI device. SPI communication pins in ATmega324p microcontroller are:
```
-> MISO (Master In Slave Out)
-> MOSI (Master Out Slave In)
-> SCK (Shift Clock)
-> SS (Slave Select)
```
The aim of this application is to build a project that uses SPI communication to exchange data between two Atmega324p microcontrollers. An 16X2 LCD display is interfaced with each microcontrollers. The master microcontroller will send continuous count to slave microcontroller.The sent and received data will be printed on the two 16x2 LCD displays. The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment.The system is designed and simulated using Proteus simulation software.

## Hardware Requirements

```
      1- Two Atmega324p microcontrollers
      2- Two 16x2 LCD displays
      3- Proteus Debuggers and Virtual Instruments Mode (SPI)
```
## Drivers

```
      1_MCAL
          -> SPI_Master
          -> SPI_Slave
      2_HAL
          -> LCD_Drive
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/2d81c7f5-a250-43d2-9c9b-997de64e67dc" width="800">
