# Project:  I2C communication using two Atmega324p Microcontrollers

## The aim
I2C (Inter-Integrated Circuit) is a serial bus interface connection protocol. It is also called TWI (two-wire interface) since it uses only two wires for communication. In addition, a communication interface from a master microcontroller to slave microcontroller uses only two wires SCL and SDA. Most of TWI slave device left these two pins in open-drain, requires two external pull up resistor with a resistance between 4.7 kΩ to 10 kΩ. 
The aim of this application is to build a project that uses I2C communication to exchange data between two Atmega324p microcontrollers. An 16X2 LCD display is interfaced with each microcontrollers. The master microcontroller will send continuous count to slave microcontroller.The sent and received data will be printed on the two 16x2 LCD displays. The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. Proteus software is utilized for designing this circuit. 

## Hardware Requirements

```
      1- Two Atmega324p microcontrollers
      2- Two 16x2 LCD displays
      3- Proteus Debuggers and Virtual Instruments Mode (I2C)
```
## Drivers

```
      1_MCAL
          -> I2C_Master
          -> I2C_Slave
      2_HAL
          -> LCD_Drive
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/4ceaf9d3-36e8-4996-9358-04c3f86b4c93" width="800">
