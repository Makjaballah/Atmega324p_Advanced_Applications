# Project: DS18B20 digital temperature Sensor Interface with Atmega324p Microcontroller

## The aim
DS1820 series is series of digital temperature sensor developed by Maxim Integrated. It uses one wire protocol. The microcontroller accesses only one digital pin working in both direction. The ds18b20 digital temperature sensor has only three pins, two pins are supply voltage and one other is the data pin. The aim of this application is to read the temperature data from a ds18b20 digital temperature sensor and display it on an 16x2 LCD display. The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. The system is designed and simulated using Proteus simulation software. 

## Hardware Requirements

```
      1- Atmega324p microcontroller
      2- 16x2 LCD display
      3- DS18B20 digital temperature Sensor
      4- Proteus Debuggers and Virtual Instruments Mode (Virtual Terminal, Oscilloscope)
```
## Drivers

```
      1_MCAL
          -> UART
      2_HAL
          -> OneWire
          -> DS18B20
          -> LCD_Drive
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/ff53b152-e72c-402f-bee9-f1b28b0a79a7" width="800">
