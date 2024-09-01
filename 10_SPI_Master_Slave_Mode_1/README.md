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
The aim of this application is to build a project that uses SPI communication to exchange data between two Atmega324p microcontrollers. A push-button is connected to GPIO port PC2 of the master microcontroller to send a counting data to slave device. The slave microcontroller receive data via SPI comminucation and print it on a seven-segment LED display. The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. The Proteus simulation software is used for simulating the system components and verifying their functionality.

## Hardware Requirements

```
      1- Two Atmega324p microcontrollers
      2- Seven-Segment LED Display
      3- Push button
      4- Proteus Debuggers and Virtual Instruments Mode (SPI)
```
## Drivers

```
      1_MCAL
          -> SPI_Master
          -> SPI_Slave
     
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/cb5901bb-6034-46d6-a8d3-cf0623676e1c" width="800">
