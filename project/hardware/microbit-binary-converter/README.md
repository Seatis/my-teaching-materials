# Project Exercises - Programmer's number translator

## Summary
  - [Serial port loopback](#serial-port-loopback)
  - [Wireless chat program](#wireless-chat-program)
  - [Binary to decimal converter](#binary-to-decimal-converter)
  - [Programmer's number translator](#programmer's-number-translator)
  - [Do a custom Project](#do-a-custom-project)

## Serial port loopback

### Exercise
- Connect the micro:bit to your laptop and establish a serial connection.
- Make a program on your micro:bit panel which receives new line terminated
strings from the serial port and sends it back right away.
- Try it out!

### Hints
 - serial read line
 - serial write line

## Wireless chat program

### Exercise

- Connect the micro:bit to your laptop and establish a serial connection.
- Make a program which:
 - receives new line terminated strings on it's serial port and forwards it
 through it's radio interface,
 - receives new line terminated strings on it's radio interface and forwards it
 through it's serial port.
- You can send/receive messages on your laptop if two or more micro:bits are
in the same radio group.

### Hints
 - radio set group
 - radio send string
 - on radio received receivedString

## Binary to decimal converter

### Excercise

- Connect the micro:bit to your laptop and establish a serial connection.
- Make a program which:
 - receives binary numbers as new line terminated strings (see examples)
 on it's serial port,
 - converts the received number to decimal form,
 - sends the converted number as new line terminated string (see examples)
 through it's serial port.
- Try it out with different numbers!

### Examples
Input of micro:bit|Output of micro:bit
-----|------
0010|3
1110|14
10010001|145

## Programmer's number translator

Make a program which converts various number formats into each other.
**You don't have to implement all the different modes, just pick two of them!**

### Excercise

- Connect the micro:bit to your laptop and establish a serial connection.
- Make a program which:
 - receives control messages
 - depending on the control message can go into different modes (see below)
    - can convert binary to decimal
    - can convert decimal to binary
    - can convert hex to binary
    - can convert binary to hex
    - can convert hex to decimal
    - can convert decimal to hex
- Try it out with different numbers!

### Control messages
You don't have to implement all the different modes, just pick two of them!

Message|Mode
-------|------
-B2D  |Binary to decimal
-D2B  |Decimal to binary
-H2B  |Hex to binary
-B2H  |Binary to hex
-H2D  |Hex to decimal
-D2H  |Decimal to hex

### Examples
These examples are in order, so the first row comes first on the input of
the micro:bit.

Input of micro:bit|Output of micro:bit
-----|------
-H2B|nothing, just goes into hex to binary mode
AA|10101010
-D2H|nothing, just goes into decimal to hex mode
452|1C4
452123123|1AF2D9F3

## Do a custom Project
Probably you learned all of the capabilities of the micro:bit panel. Now it's time to free your imagination and make something fascinating!

Here are some through-provoking ideas:
 - "encrypted" wireless program
 - digital clock
 - serial port number guessing game
 - door-opening detector (with acceleration sensor)
 - compass
