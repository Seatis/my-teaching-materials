# Arrays and pointers, user input, UART
*Learn how to use user input in C programs with arrays and pointers*

## Objectives
- Know how to use arrays and pointers in C language
- Understanding how UART works

## Materials & Resources
### Environment
  - Make sure that Code::Blocks is installed on your machine
  - Make sure that Atmel Studio is installed on your machine

### Training
#### C programming language
##### Arrays
| Material | Duration |
|:---------|-----:|
| [Introduction to arrays](https://www.youtube.com/watch?v=LEHaSSYreeo) | 5:21 |
| [char arrays](https://www.youtube.com/watch?v=7F-Q2oVBYKk) | 5:46 |
| [int and float arrays](https://www.youtube.com/watch?v=IPYA3b3_nyk) | 8:08 |
| [Arrays](http://www.w3schools.in/c-tutorial/arrays/) | - |
| [Strings](http://www.w3schools.in/c-tutorial/strings/) | - |
| [`strcat` and `strcpy`](https://www.youtube.com/watch?v=-SSsm0gVu3o) | 9:05 |
| [string.h function reference](http://www.cplusplus.com/reference/cstring/) | - |

##### User input
| Material | Duration |
|:---------|-----:|
| [`scanf` usage](https://www.youtube.com/watch?v=hSHFjPvqFjw) | 5:21 |
| [`puts` and `gets` usage](https://www.youtube.com/watch?v=yvpCxgV3AZo) | 6:15 |
| [stdio.h function reference](http://www.cplusplus.com/reference/cstdio/) | - |

##### Pointers
This topic usually blows every C newbie's mind. The pointers are quite confusing
but they are very useful tools in C.

| Material | Duration |
|:---------|-----:|
| [Introduction to pointers](https://www.youtube.com/watch?v=5BpYD7TxvKU) | 9:55 |
| [Dereference pointers](https://www.youtube.com/watch?v=vjq-13YADeI) | 4:53 |
| [C - Pointers](https://www.tutorialspoint.com/cprogramming/c_pointers.htm) | - |
| [Pointers](http://www.w3schools.in/c-tutorial/pointers/) | - |
| [Arrays and pointers](https://www.youtube.com/watch?v=sq6n8dL117c) | 9:48 |
| [Strings and pointers](https://www.youtube.com/watch?v=-9fqo94G6YU) | 6:44 |
| [Pass by Reference vs Pass by Value](https://www.youtube.com/watch?v=wAmq8eIkdI8) | 8:11 |
| [Passing Arrays as Function Arguments in C](https://www.tutorialspoint.com/cprogramming/c_passing_arrays_to_functions.htm) | - |

#### Electronics
##### Serial communications
| Material | Duration |
|:---------|-----:|
| [maxEmbedded.com - Serial communications](http://maxembedded.com/2013/09/serial-communication-introduction)| - |

##### RS-232
Read this article about RS-232, don't try to fully understand the electronics
behind it, just try to get a general understanding. The various PC software
guides not needed.

Try to find information about the following concepts in the "USART of AVR" article:
- simplex, half duplex, full duplex
- synchronous, asynchronous
- parallel vs. serial communications

| Material | Duration |
|:---------|-----:|
| [maxEmbedded.com - RS-232](http://maxembedded.com/2013/09/serial-communication-rs232-basics/)| - |

##### USART peripheral
The USART is an MCU peripheral which can be used in various serial communications.
The USART stands for Universal Synchronous and Asynchronous Receiver and Transmitter.

Try to find information about the following concepts in the "USART of AVR" article:
- TX and RX pins
- baud rate
- frame format
  - start bit
  - data bit
  - parity bit
  - stop bit

Don't try to learn the register names, because in this article another MCU is used!

| Material | Duration |
|:---------|-----:|
| [maxEmbedded.com - USART of AVR](http://maxembedded.com/2013/09/the-usart-of-the-avr/)| - |

##### USART in ATmega168PB
Read more about specific USART information in ATmega168PB's datasheet!
The following sections are needed:
- overview (25.2)
- block diagram (25.3)
- clock generation (25.4, 25.4.1, 25.4.2)
  - What registers needs to be modified for baud rate setup?
  - How to calculate baud rate?
- frame formats (25.5)
  - How to set up fram format?
- USART init (25.6)
  - baud rate
  - frame format
  - interrupt if needed
- USART transmitter (25.7)
- USART receiver (25.8-25.8.3)
- Baud rate setup examples (25.11)
- Register description (25.12)
  - UDR0
  - UCSR0A
  - UCSR0B
  - UCSR0C
  - UCSR0D
  - UBRRL and UBRRH

| Material | Duration |
|:---------|-----:|
| [ATmega168PB various pages](http://www.atmel.com/Images/Atmel-42176-ATmega48PB-88PB-168PB_Datasheet.pdf)| - |

##### Optional materials
*If you have more time and would like to know more about the topic*
- receive error detection (25.8.4)
- Asynchronous Data Reception (25.9)

## Material Review
### C programming language
#### Arrays
- char arrays = strings
- int, float
- `string.h` functions

### User input
- `scanf`, `gets`
- `stdio.h` other functions

### Pointers
- memory address
- how does variables stored in memory
- the `sizeof` function
- pointer syntax `*`, `&`
- dereferencing
- arrays and pointers
- pass by
  - reference
  - value
  - when to use them
- arrays and functions
  - pointer and size
  - can't return both at the same time
  
### Electronics
##### Serial communications
- serial vs paralell communications
  - wire count
  - clock skew
  - crosstalk
  - price
- PISO/SIPO
- examples of serial communications (RS232, RS485, PCI-E, USB, SATA, SPI, I2C, CAN, ethernet, etc.)
- asynchronous vs synchronous
- full duplex, half duplex, simplex
- baud rate vs bit/sec

##### RS-232
- signals
  - Tx, Rx
  - flow control
    - RTS/CTS
- logic levels
  - TTL
    - we will use that
    - 5V systems
  - LVTTL
    - 3V3 systems
  - RS-232
    - +- voltages
    - high voltage compared to others
  - conversions maybe needed
- loopback test
  - Tx and Rx connected on one device

##### USART peripheral
- what does it stand for (Unisversal Sync. Async. Receiver Transmitter)
  - useful for serial communications
  - "serial port" is async, hence the name UART
- what can it do
  - can be used as standard serial port or as SPI peripheral
  - SPI will be used in another workshop
- serial port physical layer
  - RX/TX
    - how to connect these (RX1-TX2, TX1-RX2)
  - flow control
    - only in specific MCUs
- baud rate
  - symbol/sec in this case equal to bit/s
- frame buildup
  - default bus state
  - start bit
  - data bits
  - parity
    - what the hack is parity
  - stop bits
- most often used frame setup
  - 8N1 (explain notation)
  - 115200 and 9600 are usual baud rates

##### USART in ATmega168PB
- overview (25.2)
- block diagram (25.3)
  - clock generator
  - data registers
  - shift registers
  - parity generators
  - pin control
- clock generation (25.4, 25.4.1, 25.4.2)
  - What registers needs to be modified for baud rate setup?
    - UBRRL and UBRRH
  - How to calculate baud rate?
    - UBBR = fosc/(BAUD*x) - 1
    - x=16 in normal mode, x=8 in double speed mode
- frame formats (25.5)
  - How to set up frame format?
    - UCSR0C
- USART init (25.6)
  - baud rate
  - frame format
  - interrupt if needed
- USART transmitter (25.7)
  - blocking mode
    - polling TX buffer empty flag
    - bad, it blocks the program
  - interrupt
    - UDRE (UsartDataRegisterEmpty)
    - TXC (TransmitComplete)
- USART receiver (25.8-25.8.3)
  - blocking mode
    - polling RXC bit
    - bad, it blocks the program
  - interrupt
    - RXC (ReceiveComplete)
- Baud rate setup examples (25.11)
  - useful table
  - always keep error minimal

## Workshop

TODO:

- TX pin have to be set to output
- TASK: write init function (see datasheet)

- TASK A
  - UART TX polling
  - UART TX interrupt with UDRE
- TASK B
  - UART RX polling
  - UART RX interrupt
- TASK C
  - STDIO

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
