# Project Exercises - DIY oscilloscope and function generator

## Summary
- [Basic oscilloscope](#basic-oscilloscope)
- [Function generator](#function-generator)
    - DC voltage mode
    - Fixed frequency sine wave mode
    - Variable frequency sine wave mode

## Tools
- Atmel Studio with Data Visualizer Extension

## Basic oscilloscope
### Exercise
- Set up the UART interface of the ATmega168PB
- Set up the ADC peripheral of the ATmega168PB
- Send data to the PC via serial port
    - Send the data as a number (not as a string!)
    - Open the Data Visualizer Extension
    - Set up the serial port
    - Set up an Oscilloscope object with the serial port as the input

### Hints
- Use [this workshop's](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/hardware/SPI-communication-ADC) ADC code as a starting point

## Function generator
### Exercises
- DC voltage mode
- Fixed frequency sine wave mode
- Variable frequency sine wave mode

### Specification
- The function generator should be controlled via UART
- DC voltage mode
    - Description
        - Gets a DC voltage level on UART
        - The given voltage level should appear on the output of the DAC
    - Parameters
        - Voltage level (float)
- sine generator (fixed frequency) mode
    - Description
        - Gets a peak-to-peak voltage level on UART
        - A fixed 1Hz sine wave should appear on the output of the DAC
            - With a DC level of Vref/2
            - With a peak-to-peak voltage level as given with UART
    - Parameters
        - peak-to-peak voltage (float)
- sine generator (variable frequency) mode
    - Description
        - Gets a peak-to-peak voltage level on UART
        - Gets a frequency value on UART
        - A sine wave should appean on the output of the DAC
            - With a DC level of Vref/s
            - With the given peak-to-peak voltage
            - With the given frequency
    - Parameters
        - peak-to-peak (float)
        - frequency (Hz)

#### Mode selection specification
| UART control string | Goes into mode | param1 | param2 | Example |
|:|:|
| -DC,**param1**\r\n | DC mode | DC voltage level [V] (float) | - | -DC,1.25\r\n |
| -SINEFIX,**param1**\r\n | Fixed frequency SINE mode | Peak-to-peak voltage level [V] (float) | - | -SINEFIX,0.5\r\n |
| -SINEVAR,**param1**,**param2**\r\n | Variable frequency SINE mode | Peak-to-peak voltage level [V] (float) | Frequency [Hz] (integer) | -SINEVAR,1.12,11\r\n |

### Hints
- Use the basic oscilloscope code as a starting point
- Add the MCP4821 driver files to the project
    - It was written on a [previous workshop](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/hardware/SPI-communication-ADC)
- Use the ADC as an oscilloscope to verify your solution
- For sine wave generation
    - Use the math.h `sin()` functions
- The sine generators may only work properly using interrupts
    - You have to send the data to the DAC at fixed time intervals
    - You may want to use timer interrupts to trigger the SPI data sending
    - In the variable frequency mode you have to modify the fixed time intervals
