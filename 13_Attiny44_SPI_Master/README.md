# Project: SPI communication using AVR family-based ATiny44 microcontroller (Master) and ATmega324p microcontroller (Slave)

## The aim
Serial communication protocols provides the means to communicate for microcontrollers with external hardware, peripherals or other microcontrollers. USART, SPI, I2C are some of the popular serial communication protocols in embedded world. In order to facilitate serial communication in ATtiny44 microcontroller, it is equipped with a Universal Serial Interface USI module. This USI module can operate in Two wire Synchronous data transfer ( I2C protocol ) and Three wire Synchronous data transfer (SPI protocol) modes.

The aim of this application is to build a project that uses SPI communication to exchange data between the ATiny44 microcontroller (Master) and the ATmega324p microcontroller (Slave). A push-button is connected to GPIO port PA2 of the master microcontroller. While, the push-button is not pressed, the master microcontroller send hex values from 0 to F to slave device. The slave microcontroller receive data via SPI then sets the PORTD outputs to turn individual segments of the LED display on or off, thus displaying a digit from 0 to F. The digits 0 to F should show in ascending order on the seven-segment LED display, and then repeat.
The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. Proteus software is utilized for designing this circuit.

## Hardware Requirements

```
      1- Atmega324p microcontroller
      2- ATiny44 microcontroller
      3- Seven-Segment LED Display
      4- Push button
      5- Proteus Debuggers and Virtual Instruments Mode (SPI)
```
## Drivers

```
      1_MCAL
          -> USI_SPI_Master
          -> SPI_Slave
 
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/9cc85d3f-dd16-47a9-82c3-8c86ec5c781c" width="800">
