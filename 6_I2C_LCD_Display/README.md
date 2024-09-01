# Project: Interface an I2C LCD with Atmega324p Microcontroller

## The aim
If you’ve ever attempted to connect an 16x2 LCD display to an Atmega324p microcontroller, you’ve probably noticed that it uses a lot of microcontroller pins. Even in 4-bit mode, Atmega324p microcontroller requires seven connections. To avoid this, we can use an I2C LCD display. It only uses two GPIO pins and can be shared with other I2C devices. The aim of this application is to interface an 16x2 LCD display with Atmega324p microcontroller using the PCF8574 module. The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. The main circuit diagram was simulated using the real time simulation tool software, Proteus Design Suite.

## Hardware Requirements

```
      1- Atmega324p microcontroller
      2- 16x2 LCD display
      3- PCF8574 module: IIC/I2C Serial Interface Adapter Module
      4- Proteus Debuggers and Virtual Instruments Mode (I2C)
```
## Drivers

```
      1_MCAL
          -> I2C_Master
      2_HAL
          -> LCD_I2C_Drive
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/a358b341-fb83-4c60-a0bb-77dd28aa5a23" width="800">
