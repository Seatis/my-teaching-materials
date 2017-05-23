# I2C communication
*Learn a new serial communication protocol*

## Objectives
- Learn how does the I2C communication protocol works

## Materials & Resources
### Environment
- Make sure that Atmel Studio is installed on your machine
- Make sure that Data Visualizer plugin installed in Atmel Studio

### Training

#### I2C communication
Read these articles on I2C communication.

In "Inter-Integrated Circuits – I2C " just get a global
understanding of the usage of the peripheral.



| Material | Duration |
|:---------|-----:|
| [maxEmbedded - I2C Basics](http://maxembedded.com/2014/02/inter-integrated-circuits-i2c-basics/) | - |
| [Easy I2C: Introduction to I2C](https://www.youtube.com/watch?v=qeJN_80CiMU) | 3:50 |
| [ATmega168PB datasheet](http://www.atmel.com/Images/Atmel-42176-ATmega48PB-88PB-168PB_Datasheet.pdf) | - |

Also read the corresponding pages of the datasheet of ATmega168PB (278-314). OK, little bit long, check the main thing such as communication modes, frame format, registers, pins and wiring:
 - 27.2. Two-Wire Serial Interface Bus Definition
 - 27.3. Data Transfer and Frame Format
 - 27.5. Overview of the TWI Module
 - 27.6. Using the TWI
    - Figure 27-10. Interfacing the Application to the TWI in a Typical Transmission!!!444!!!
 - 27.7. Transmission Modes

 - 27.9. Register Description

## Material Review
### I2C communication
- Inter-Integrated Circuits
    - Master/Slave  
- Physical layer
    - Signals
        - SDA
        - SCL
    - Pull up
    - Data transfering
       - Master Transmitter (MT)
       - Master Receiver (MR)
       - Slave Transmitter (ST)
       - Slave Receiver (SR)  
    - Multiple slaves
- I2C of ATmega168PB
    - registers
        - TWBR bit Rate Register (27.9.1.)
        - TWSR status register (27.9.2.)
        - TWAR address register (27.9.3.)
        - TWDR data register (27.9.4.)
        - TWCR control register (27.9.5.)
    - typical init procedure
        - set master or slave mode
        - set slave address
        - set I2C mode
        - set bit rate
        - enable I2C interrupt if needed
        - enable I2C peripheral

## Workshop
### I2C
#### Setting up the hardware
Make the following connection between the IC and the ATmega168PB Xplained board

| TC74 pin | Pin function | Connect to ATmega168PB pin|
|-|-|-|
|1|NC|NC|
|2|SDA|SDA (PC4)|
|3|GND|GND (0V)|
|4|SCLK|SCL (PC5)|
|5|VDD| VCC |

Also:
 - don't forget the pull up resistors (external or internal)

[TC74A0 datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf)

[ATmega168PB Xplained user manual](http://www.atmel.com/Images/Atmel-42381-ATmega168PB-Xplained-Mini_UserGuide.pdf)

#### Writing driver software
You are going to write your first external device handler software. It is useful
to put all the hardware specific code in a separate .c and .h file, so it can be
reused in another project just be copying those files.

Steps:
- create a new atmel studio project
- copy the [following files](workshop/AtmelStudio/MC4821_DRIVER) to the project folder (next to the automatically generated main.c file)
- overwrite the files if asked
- add the files to the project
- write the code where asked (marked with "TODO")
    - always test the code after you wrote a few lines of code
    - write the needed functions in the following order
        - `MCP4821_Init()`
        - `MCP4821_SendRawData(uint16_t data)`
        - `MCP4821_SendData(MCP4821_Data_t* data)`
- test the driver with the external ic


#### Writing driver software
Like in the previous project we provide you template files.

Steps:
- create a new atmel studio project
- copy the [following files](#) to the project folder (next to the automatically generated main.c file)
- overwrite the files if asked
- add the files to the project
- write the code where asked (marked with "TODO")
    - always test the code after you wrote a few lines of code
    - write the needed functions in the following order
        - `ADC_Init()`
        - `ADC_Read()`
- test the driver with the potentiometer, for example
    - turn on the LED if the measured voltage is higher than a predefined value or
    - send the data to your PC via serial port

## Individual Workshop Review
Please follow the styleguide: [Our C styleguide](https://github.com/greenfox-academy/teaching-materials/blob/master/styleguide/c.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes placed on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?

## Solutions
[Solutions](#)
