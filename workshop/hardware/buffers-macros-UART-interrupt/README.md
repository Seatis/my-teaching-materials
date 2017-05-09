# Buffers and preprocessor macros in C, UART with interrupt
*Meet the different buffering techniques, learn how to use preprocessor macros and
how to use the UART peripheral properly*

## Objectives
- Know the most common buffering techniques
- Practice preprocessor macros
- Use the UART peripheral properly with interrupt

## Materials & Resources
### Environment
  - Make sure that Code::Blocks is installed on your machine
  - Make sure that Atmel Studio is installed on your machine

### Training
#### Buffering
Read these articles about the data buffers. The overview sections are enough for us,
the other parts contain advanced information.

| Material | Duration |
|:---------|-----:|
| [Data buffer](https://en.wikipedia.org/wiki/Data_buffer) | - |
| [FIFO](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) | - |
| [LIFO](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) | - |
| [Circular buffer](https://en.wikipedia.org/wiki/Circular_buffer) | - |

#### Preprocessor macros
| Material | Duration |
|:---------|-----:|
| [The C Preprocessor](https://www.youtube.com/watch?v=pP4laGRP-c0) | 5:57 |
| [Preprocessor macro list](http://www.w3schools.in/c-tutorial/preprocessors/) | - |

#### UART with interrupt
Take a look at the USART section of the ATmega168PB datasheet, especially looking for
interrupt related information.

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

#### Optional materials
*If you have more time and would like to know more about the topic*

[The GNU C Preprocessor](http://tigcc.ticalc.org/doc/cpp.html)

## Material Review

### Preprocessor macros
- when does it compiles?
    - at the start of the compilation process
- why and when do we use them
- substitution
    - #include
    - #define/#undef
    - #ifdef/#ifndef
- inclusion
    - #if/#elif/#else/#endif
- compiler control
    - #error

### Buffering
- Data buffer
    - why do we need it (i/o)
- FIFO
    - good/bad
    - queue
- LIFO
    - good/bad
    - stack
- Non-circular buffer
    - how does it work
    - good/bad
    - easy to use as a LIFO
- Circular buffer
    - how does it work
    - good/bad
    - easy to use as a FIFO

### UART with interrupt
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
- USART init (25.6)M
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
TODO: - next day do a circular buffer struct
### Preprocessor macros
- define
- ifdef/ifndef
- if/elif/else/endif (máshogy fordul a program tőle)
- error

### UART properly
- create circular receive and transmtit buffer
- write TX ISR using the circular tx buffer
- write RX ISR using the circular rx buffer

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
