# Project: PIR Motion Sensor Interface with Atmega324p Microcontroller

## The aim
The PIR sensor is interfaced with Atmega324p microcontroller to detect the motion around the environment. Atmega324p considers any voltage between 2V to 5V as logic high. Hence PIR sensor is directly interfaced to the input pin of the microcontroller. The aim of this application is to read the status of the output of the PIR sensor and switch ON the LED when there is a motion detected and switch OFF the LED when there is nothing. Output pin of the PIR sensor is connected to GPIO port PC0 of the Atmega324p microcontroller. LED is connected through the GPIO port PA0 of the microcontroller. The Embedded C is applied to compile program in Eclipse IDE for Embedded C/C++ Developers programming environment. Proteus software is utilized for designing this circuit.

## Hardware Requirements

```
      1- Atmega324p microcontroller
      2- 16x2 LCD display
      3- PIR Sensor
      4- LED
      5- Proteus Debuggers and Virtual Instruments Mode (Virtual Terminal, Oscilloscope)
```
## Drivers

```
      1_MCAL
           -> UART
      2_HAL
          -> LCD_Drive
```
## Simulation of the main circuit diagram using Proteus Design Suite software
<img src="https://github.com/user-attachments/assets/a01c515a-38b5-48c6-b94a-11d3222babfb" width="800">
