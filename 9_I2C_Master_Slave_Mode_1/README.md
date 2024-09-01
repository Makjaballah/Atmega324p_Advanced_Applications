# Project: I2C communication using two Atmega324p Microcontrollers

## The aim
I2C (Inter-Integrated Circuit) is a serial bus interface connection protocol. It is also called TWI (two-wire interface) since it uses only two wires for communication. In addition, a communication interface from a master microcontroller to slave microcontroller uses only two wires SCL and SDA. Most of TWI slave device left these two pins in open-drain, requires two external pull up resistor with a resistance between 4.7 kΩ to 10 kΩ. 
The aim of this application is to build a project that uses I2C communication to exchange data between two Atmega324p microcontrollers. A push-button is connected to GPIO port PC2 of the master microcontroller to send a counting data to slave device . The slave microcontroller receive data via I2C communication and print it on a seven-segment LED display. The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. Proteus software is utilized for designing this circuit. 

## Hardware Requirements

```
      1- Two Atmega324p microcontrollers
      2- Seven-Segment LED Display
      3- Push button
      4- Proteus Debuggers and Virtual Instruments Mode (I2C)
```
## Drivers

```
      1_MCAL
          -> I2C_Master
          -> I2C_Slave
      
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/bc652be7-d84c-4635-aa0b-2daa9fceba19" width="800">
