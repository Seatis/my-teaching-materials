# SPI communication, ADCs ans DACs
*Learn a new serial communication protocol and get familiar with digital-analog conversions*

## Objectives
- Learn how does the SPI communication protocol works
- Learn how to use an external DAC
- Know how to use the ADC peripheral of the ATmega168PB

## Materials & Resources
### Environment
- Make sure that Atmel Studio is installed on your machine

### Training

#### SPI communication
Read these articles on SPI communication.

In "The SPI of the AVR" just get a global
understanding of the usage of the peripheral.

Also read the corresponding pages of the datasheet of ATmega168PB (231-240).

| Material | Duration |
|:---------|-----:|
| [maxEmbedded - SPI Basics](http://maxembedded.com/2013/11/serial-peripheral-interface-spi-basics/) | - |
| [maxEmbedded - The SPI of the AVR](http://maxembedded.com/2013/11/the-spi-of-the-avr/) | - |
| [ATmega168PB datasheet](http://www.atmel.com/Images/Atmel-42176-ATmega48PB-88PB-168PB_Datasheet.pdf) | - |

#### DACs
We are going to use an external DAC IC with SPI communication.

At first watch a video on how a DAC works.

| Material | Duration |
|:---------|-----:|
| [AddOhms - How Voltage Dividers Work](https://www.youtube.com/watch?v=EQtwsWJuUPs) | 5:17 |
| [Collin's Lab: Digital to Analog Converter](https://www.youtube.com/watch?v=b-vUg7h0lpE) | 4:35 |

We will use the [MCP4821](http://ww1.microchip.com/downloads/en/DeviceDoc/22244B.pdf) DAC.
It's datasheet is quite long and contains lot's of informations. Don't start to read it,
we will do that during the material review.

#### ADCs
At first watch a video on how the SAR and Flash ADC works. After that read the following sections
of the datasheet of the ATmega168PB:
- Overview (29.2.)
- Starting a conversion (29.3.)
- Prescaling and Conversion Timing (29.4.)
- Register description (29.9.)
    - ADMUX (ADC multiplexer)
        - selecting reference voltage
        - selecting right/left adjusted mode
        - selecting channel
    - ADCSRA (ADC Control and Status Register A)
        - enable
        - start
        - interrupt enable
        - prescaler
    - ADCL and ADCH
        - result data registers
        - format depends on ADLAR bit of ADMUX register

| Material | Duration |
|:---------|-----:|
| [GreatScott! - ADC (Analog to Digital Converter)](https://www.youtube.com/watch?v=EnfjYwe2A0w) | 6:47 |

## Material Review
### SPI communication
- Serial peripheral Bus
- Basic info
    - Master/Slave  
    - Full duplex
- Physical layer
    - Signals
        - MISO
        - MOSI
        - SS (negated)
        - SCK
    - 8-bit shift registers
    - Data transfering
        - SS (negated)
        - Shift-out/shift-in    
    - Multiple slaves
    - SPI modes
        - CPOL (clock polarity)
            - idle state of SCK line
            - zero (0)
            - one (1)
        - CPHA (clock phase)
            - sampling of data lines
            - rising edge (0)
            - falling edge (1)
- AVR ISP programmers use SPI to program the MCU
- SPI of ATmega168PB
    - registers
        - SPCR control register (24.5.1)
        - SPSR status register (24.5.2.)
        - SPDR data register (24.5.3.)
    - typical init procedure
        - set master or slave mode
        - set data order
        - set SPI mode
            - set CPOL
            - set CPHA
        - set clock rate
        - enable SPI interrupt if needed
        - enable SPI peripheral

### DACs
- Voltage divider
    - schematic
    - thumb rule
- DAC
    - how does it works
    - parameters
        - sampling rate
        - bits
        - reference voltage
- MCP4821
    - parameters
        - 12bits
        - internal 2.048V reference
        - 20MHz SPI clock frequency
        - selectable gain (1x/2x)
    - block diagram
        - SPI
        - internal reference
        - output buffer
            - 1x/2x gain
    - SPI interface
        - command
            - gain
            - shutdown
            - data

### ADCs
- Types
    - Flash
    - SAR
- Parameters
    - sampling rate
        - Nyquist-Shannon
        - thumb rule
    - bits
    - reference voltage
- ATmega168PB
    - Parameters
        - 10bit SAR
        - max. 15kSPS
        - 6 input channel
        - interrupt at end of conversion
        - 1.1V internal reference
    - Description
        - block diagram
        - multiplexer
            - channels
            - reference voltages
        - reference voltage
            - internal
            - external
        - sampling clock
            - prescaler
        - register description
            - ADMUX (ADC multiplexer)
                - selecting reference voltage
                - selecting right/left adjusted mode
                - selecting channel
            - ADCSRA (ADC Control and Status Register A)
                - enable
                - start
                - interrupt enable
                - prescaler
            - ADCL and ADCH
                - result data registers
                - format depends on ADLAR bit of ADMUX register

## Workshop
### SPI DAC
#### Setting up the hardware
Make the following connection between the IC and between the ATmega168PB Xplained board

| MCP4821 pin | Pin function | Connect to |
|-|-|-|
|1|VDD|+5V|
|2|!CS|SS (PB2)|
|3|SCK|SCK (PB5)|
|4|SDI|MOSI (PB3)|
|5|!LDAC| GND (0V) |
|6|!SHDN| x |
|7|VSS| GND (0V) |
|8|VOUT| output |

Also:
- put a 100nF capacitor between the VDD and VSS pins as close as possible to the DAC IC
- put a 1uF capacitor between the VDD and VSS pins as close as possible to the DAC IC
- put a 1uF capacitor between the VOUT and VSS pins as close as possible to the DAC IC

[MCP4821](http://ww1.microchip.com/downloads/en/DeviceDoc/22244B.pdf)

[ATmega168PB Xplained user manaul](http://www.atmel.com/Images/Atmel-42381-ATmega168PB-Xplained-Mini_UserGuide.pdf)

#### Writing driver software
You are going to write your first external device handler software. It is useful
to put all the hardware specific code in a separate .c and .h file, so it can be
reused in another project just be copying those files.

Steps:
- create a new atmel studio project
- copy the [following files](#) to the project folder (next to the automatically generated main.c file)
- overwrite the files if asked
- add the files to the project
- write the code where asked (marked with "TODO")
    - always test the code after you wrote a few lines of code
    - write the needed functions in the following order
        - `MCP4821_Init()`
        - `MCP4821_SendRawData(uint16_t data)`
        - `MCP4821_SendData(MCP4821_Data_t* data)`
- test the driver with the external DAC

### ADC
#### Setting up the hardware
Make the following connections:
- connect the AREF pin to +5V with a low resistance resistor (< 1kohm)
- connect the potentiometer to the devboard
    - the middle pin to PC0 (ADC channel 0)
    - the pin on the left to GND (0V)
    - the pin on the right to VCC (+5V)

#### Writing driver software
Like in the previous project we provide you template files.

Steps:
- create a new atmel studio project
- copy the [following files](#) to the project folder (next to the automatically generated main.c file)
- overwrite the files if asked
- add the files to the project
- write the code where asked (marked with "TODO")
    - always test the code after you wrote a few lines of code
- test the driver with the potentiometer
    - for example turn on the LED if the measured voltage is higher than a predefined value

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
