# Project: I2C communication using AVR family-based ATiny44 microcontroller (Master) and ATmega324p microcontroller (Slave)

## The aim
I2C or Inter Integrated circuit is a popular serial communication protocol built in almost every modern microcontrollers. This protocol uses full duplex communication and uses only two wires to exchange data. ATtiny44 microcontroller is equipped with Universal Serial Interface aka USI which can be configured to operate in I2C mode. I2C mode using this USI interface is also referred as Two wire mode.

The aim of this application is to build a project that uses I2C communication to exchange data between the ATiny44 microcontroller (Master) and the ATmega324p microcontroller (Slave). A push-button is connected to GPIO port PA1 of the master microcontroller. While, the push-button is pressed, the master microcontroller send hex values from 0 to F to slave device. The slave microcontroller receive data via I2C then sets the PORTB outputs to turn individual segments of the LED display on or off, thus displaying a digit from 0 to F. The digits 0 to F should show in ascending order on the seven-segment LED display, and then repeat.
The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. Proteus software is utilized for designing this circuit.

## Hardware Requirements

```
      1- Atmega324p microcontroller
      2- ATiny44 microcontroller
      3- Seven-Segment LED Display
      4- Push button
      5- Proteus Debuggers and Virtual Instruments Mode (I2C)
```
## Drivers

```
      1_MCAL
          -> USI_I2C_Master
          -> I2C_Slave
      
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/46e455cf-6eac-41bb-9fe0-e9a4988b1668" width="800">
