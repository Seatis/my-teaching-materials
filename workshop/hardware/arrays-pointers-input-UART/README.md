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

TODO:
- on serial communications
  - http://maxembedded.com/2013/09/serial-communication-introduction/#UARTnUSART
   - serial vs paralell communications
   - why do we use serial for high speed instead of paralell
      - wire count (price)
      - latency
         - wire capacitance
      - cheaper line drivers
   - examples of serial communications (RS232, RS485, PCI-E, USB, SATA, SPI, I2C, CAN, ethernet stb.)
   - async vs sync
   - full duplex, hald duplex, simplex

- USART peripheral
  - what is it stand for (Unisversal Sync. Async. Receiver Transmitter)
    - useful for serial communications
    - serial port is async, hence the name UART
  - what can it do
    - can be used as standard serial port, or as SPI peripheral
    - SPI will be used in another workshop
  - serial port physical layer
    - RX/TX
      - how to connect these (RX1-TX2, TX1-RX2)
    - flow control
      - ...
    - signal levels
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
- UART peripheral in ATmega168PB
  - 241-271
  - sections
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
      - TASK: write init function (see datasheet)
    - USART transmitter (25.7)
      - blocking mode
        - polling TX buffer empty flag
        - bad, it block the program
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
      -
- optional info
  - receive error detection (25.8.4)
  - Asynchronous Data Reception (25.9)
- TASK A
  - UART TX polling
  - UART TX interrupt with UDRE
- TASK B
  - UART RX polling
  - UART RX interrupt
- TASK C
  - STDIO




| Material | Duration |
|:---------|-----:|
| [ATmega168PB I/O-Ports](http://www.atmel.com/Images/Atmel-42176-ATmega48PB-88PB-168PB_Datasheet.pdf) (pages 105-108) | - |


## Material Review

### Electronics

### C programming language

## Workshop

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
