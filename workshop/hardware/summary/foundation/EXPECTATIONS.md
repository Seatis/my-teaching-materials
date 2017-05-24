# Foundation phase expectations

## Source code handling
- Version control (GIT)
    - fork
    - init
    - clone
    - add
    - stage
    - commit
    - push
    - pull
- Command line
    - copy, move, delete and modify file
- Styleguide

## Electronics theory
- Basics
    - Current
    - Voltage
    - Power
    - Resistors
    - Capacitors
- Analog circuit analysis
    - Series and parallel resistors
    - Voltage dividers
- Digital circuits
    - AND, OR, XOR, NAND, NOR gates
    - What is inside an MCU
- SI prefixes
    - from pico to tera
- Binary numbers
    - Conversion between binary-decimal-hexadecimal systems
- Digital communication protocols
    - basics
        - Synchronous/Asynchronous
        - Duplex/Half-duplex/Simplex
    - UART (RS-232, aka. serial port)
        - signals, voltage levels (physical layer)
        - protocol
            - frame formats
            - baud rate
    - SPI
        - signals, voltage levels (physical layer)
        - protocol
            - master/slave
            - SS
            - bit order
            - modes (CPOL, CPHA)

## C programming language
- The C Compiler
    - preprocessor
    - compiler
    - assembler
    - linker
- Expressions and control flow
    - Comments and Keywords
    - Variables
        - Datatypes
        - stding.h types
        - Constants (const)
        - Literals
            - integers (12)
            - binary (0b1100)
            - hex (0xC)
            - float (12.0)
    - Operators
        - Math operators
        - Logical operators
        - Bitwise operators
    - Control flow
        - if statement
        - else, else-if
        - nested if
        - ternary operator (?: operator)
        - switch
    - Loops
        - while
        - do-while
        - for loop
        - nested loops
- Functions
    - syntax
    - parameters
    - return value
    - variable scopes
- Arrays
    - syntax
    - usage
    - sizeof()
- Pointers
    - memory address
    - operators
        - declaration (\*)
        - dereferencing (\*)
        - address (&)
    - pass by pointer vs. pass by value
    - arrays and pointers
    - arrays as function parameters
- Dynamic memory allocation
    - malloc()
    - calloc()
    - free()
    - realloc()
    - avoiding memory leak
- Data structures
    - struct
    - bit field
    - unions
    - operators
        - accessing member of variable (.)
        - accessing member of pointer (->)
    - enum
- Preprocessor macros
    - #include
    - #define/#undef
    - #if/#elif/#else/#endif
    - #ifdef/#ifndef/#endif
    - #error
    - inclusion guards
- Standard library functions
    - stdio.h (Standard Input/Output)
    - stdlib.h (Standard Library)
    - string.h (String library)

## Embedded C
- ATmega168PB architecture
    - what is inside
    - interrupt system
        - vector table
        - global interrupt mask bit
        - individual interrupt mask bits
- GPIO usage
    - input
    - output
    - interrupt-on-change
- Timer usage
    - Normal mode
        - overflow interrupt
    - CTC mode
        - compare interrupt
- USART usage
    - in UART mode (RS-232, aka. serial port)
    - receive/transmit interrupt
- circular buffers
    - usage
    - implementation
    - using with UART receive
- SPI usage
    - without interrupt
    - with interrupt
- ADC usage
    - without interrupt
    - with interrupt
- DAC (MCP4821) usage