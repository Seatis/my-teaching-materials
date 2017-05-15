# Project Exercises - DIY oscilloscope and function generator

## Summary
- [Basic oscilloscope](#basic-oscilloscope)
- [DC Function generator](#DC Function generator)
- [Fixed frequency sine wave function generator](#fixed-frequency-sine-wave-function-generator)
- [Variable frequency sine wave function generator](#variable-frequency-sine-wave-function-generator)
- [Hardcore mode function generator](#hardcore-mode-function-generator)

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

## DC Function generator
### Specification
- The DC function generator should be controlled via UART
- It receives a floating point number in Volts
- This received voltage then appears on the output of the DAC
    - if the user gives too low voltage put out the minimal voltage
    - if the user gives too high voltage put out the maximal voltage
- Output voltage minimum is 0V
- Output voltage maximum is 4.096V

### Example
| UART input | Voltage on the output of the DAC |
|------------|----------------------------------|
|1.42|1.42V|
|0|0V|
|52|4.096V|

### Hints
- Use the basic oscilloscope code as a starting point
- Add the MCP4821 driver files to the project
    - It was written on a [previous workshop](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/hardware/SPI-communication-ADC)
- Use the ADC as an oscilloscope to verify your solution
- You will probably need a function to check if the user sent control message via UART
    - The circular buffer's read and write pointers are pointing to the same address if the buffer is empty
- Use the `gets()` function to read the user string
- Use the `atof()` function to convert a string to a float number

## Fixed frequency sine wave function generator
### Specification
- The fixed frequency sine wave function generator should be controlled via UART
- It receives a floating point number in Volts
- A sine wave should appear on the output of the DAC with:
    - predefined custom frequency
    - a peak-to-peak voltage as given in the received voltage level
    - about 2V DC offset
    - if the user gives too low voltage put out the minimal voltage
    - if the user gives too high voltage put out the maximal voltage
- Output peak-to-peak voltage minimum is 0V
- Output peak-to-peak voltage maximum is 4.096V

### Example
| UART input | Voltage on the output of the DAC |
|------------|----------------------------------|
|1|sine wave between about 1.5V and 2.5V|
|0|0V|
|52|sine wave between about 0V and 4V|

### Hints
- Use the DC function generator code as a starting point
- Use the ADC as an oscilloscope to verify your solution
- Use the `sin()` function from the `math.h` library
- You will probably need a timer interrupt to put out the sine voltage
    - We suggest to use CTC timer interrupt
    - [Here](https://github.com/greenfox-academy/teaching-materials/blob/master/workshop/hardware/solutions/arrays-pointers-input-UART/AtmelStudio/CA_TC0_CTC_mode_example.c) you can find an example code

## Variable frequency sine wave function generator
### Specification
- The variable frequency sine wave function generator should be controlled via UART
- It receives a floating point number in Volts
- It also receives an integer in Hz
- A sine wave should appear on the output of the DAC with:
    - the given frequency
    - a peak-to-peak voltage as given in the received voltage level
    - about 2V DC offset
    - if the user gives too low voltage put out the minimal voltage
    - if the user gives too high voltage put out the maximal voltage
    - you can define minimal and maximal frequency values, but you should check what the user have entered
- Output peak-to-peak voltage minimum is 0V
- Output peak-to-peak voltage maximum is 4.096V

### Example
| UART input | Voltage on the output of the DAC |
|------------|----------------------------------|
|1,2|2Hz sine wave between about 1.5V and 2.5V|
|3.42,10|10Hz sine wave between about 0.29V and 3.71V
|52,12|12Hz sine wave between about 0V and 4V|

### Hints
- Use the fixed frequency function generator code as a starting point
- Use the ADC as an oscilloscope to verify your solution
- Take a look at the `strtok()` function
- You will probably need a timer interrupt to put out the sine voltage

## **HARDCORE MODE** function generator
### Specification
- The function generator can be controlled via UART
- It can put out
    - DC voltage
    - fixed frequency sine wave
    - variable frequency sine wave
- The modes can be adjusted by UART commands

### Command list
| UART input | Mode |
|------------|----------------------------------|
|-DC,1|DC voltage, 1V output|
|-SF,3.42|fixed freq. sine wave mode, custom frequency sine wave between about 0.29V and 3.71V |
|-SV,52,12|variable freq. sine wave mode, 12Hz sine wave between about 0V and 4V|

### Hints
- Use the previous exercises as staring point
