# Project: 74HC165 shift register SPI interface with Atmega324p Microcontroller

## The aim
Reading a digital data from 74HC165 shift register require the SPI module of the microcontroller. The aim of this application is to use the SPI communication protocol of the Atmega324p microcontroller to read the digital data from 74HC165 shift register. Reading the data from this shift register required to send 8 SPI clock pulse to the device. Each data bit of 74HC165 is shift out every rising edge of the pulse. The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. The main circuit diagram was simulated using the real time simulation tool software, Proteus Design Suite.

## Hardware Requirements

```
      1- Atmega324p microcontroller
      2- 74HC165 shift register
      3- DIP switch
      5- Proteus Debuggers and Virtual Instruments Mode (Virtual Terminal)
```
## Drivers

```
      1_MCAL
          -> UART
          -> SPI_Master

```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/99d11a13-83fe-497d-acef-bf2dcbfeb046" width="800">
