# micro:bit deeper
This workshop teaches what is a serial port and how to use it in an advanced
project.

## Summary
 - [Objectives](#objectives)
 - [Materials & Resources](#materials-&-resources)
 - [Material Review](#material-review)
 - [Workshop](#workshop)

## Objectives
  - Learn the basic laws in electronics
  - Get familiar with the SI prefixes
  - Be a hexadecimal-decimal-binary calculator
  - Know what is a serial port and how to use it for communication

## Materials & Resources

### Tools to install at home
We will use the serial port of the micro:bit in a project. You will need a
program which allows to send and receive data between your laptop and micro:bit.

**Windows users**

Download and install [RealTerm](https://sourceforge.net/projects/realterm/).

Donwload and install [mbed serial driver](https://developer.mbed.org/handbook/Windows-serial-configuration).

**Linux and Mac OS X users**

These operating systems contains a serial port terminal program by default.

### Training
#### Electronics
Watch these videos on the basic laws in electronics and on the SI prefixes.

| Material | Time |
|:---------|-----:|
| [Electric Current: Crash Course Physics #28](https://www.youtube.com/watch?v=HXOok3mfMLM) | 8:22 |
| [Resistors - Ohm's Law is not a real law](https://www.youtube.com/watch?v=G3H5lKoWPpY) | 5:51 |
| [DC Resistors & Batteries: Crash Course Physics #29](https://www.youtube.com/watch?v=g-wjP1otQWI) | 10:47 |
| [Circuit Analysis: Crash Course Physics #30](https://www.youtube.com/watch?v=-w-VTw0tQlE) | 10:55 |
| [Capacitors and Capacitance: Capacitor physics and circuit operation](https://www.youtube.com/watch?v=f_MZNsEqyQw) | 10:01 |
| [Capacitors and Kirchhoff: Crash Course Physics #31](https://www.youtube.com/watch?v=vuCJP_5KOlI) | 10:37 |
| [EEVblog #486 - Does Current Flow Through A Capacitor?](https://www.youtube.com/watch?v=ppWBwZS4e7A) | 17:16 |
| [Introduction to SI Prefixes - Real Chemistry](https://www.youtube.com/watch?v=nQDKEzR-vWg) | 17:16 |

#### Binary numbers
Learn how to convert binary, hexadecimal and decimal numbers into each other.

First watch theese videos:

| Material | Time |
|:---------|-----:|
| [Binary Numbers and Base Systems as Fast as Possible](https://www.youtube.com/watch?v=LpuPe81bc2w) | 5:19 |
| [How To Convert Binary To Decimal Tutorial (The Easy Way)](https://www.youtube.com/watch?v=tfKe8PPI2zs) | 4:33 |
| [How To Easily Convert Hexadecimal To Binary And To Decimal Tutorial](https://www.youtube.com/watch?v=t_kA5KQxByc) | 5:40 |

Practice the conversion algorithms! You can use [this tool](https://www.cs.ucsb.edu/~pconrad/cs16/topics/numberConversions/). The videos don't talk about the octal (base 8) numeral system which is not widely used, so just ignore those tasks. Or you can figure it out on your own :).

## Material Review

### Electronics
 - Symbols of battery (voltage source), resistor, capacitor
 - Ohm's law
 - Resistance
 - Capacitance
 - Electric power
 - Resistors and capacitors
  - Resistance vs resistor
  - Capacitance vs capacitor
 - Circuit analysis
  - Series connection of resistors/capacitors
  - Parallell connection of resistors/capacitors
 - SI prefixes
 - Plotting U(t) and I(t) graphs
 - U-I graph of resistors
 - RC circuit voltage demonstration with PicoScope

### Binary numbers
 - Numeral system basics
 - Decimal to binary
 - Binary to decimal
 - Hexadecimal system
 - Hexadecimal to binary
 - Binary to hexadecimal
 - Octal system
 - Hexadecimal to octal to binary
 - Binary to octal to hexadecimal

## Workshop
You are going to learn how to use the serial port for communication.

### Tools
 - a micro:bit panel with USB cable
 - [micro:bit PXT tool](https://pxt.microbit.org/?lang=en)
 - [RealTerm](https://sourceforge.net/projects/realterm/) or
 [screen](https://kb.iu.edu/d/acuy) (depending on operating system)
 
#### Terminal software usage
##### RealTerm
- fisrt download the mbed driver if you have earlier versions of win10
- install the driver when the microbit is connected to the USB port
- open device manager
    - plug in microbit
    - the list will be updated and a serial port will come up
    - note down the name of the port (usually "COMx", where x is a number between 0-255)
- open realterm
    - on the port tab set
       - 115200 in Baud field
    - click on Open button
    - now the port is open, ready to receive data
    - on the send tab you can send data over the serial port
    - you can specify which endline character you want to send at the end of the line (CR or LF or both)
##### Screen
- install it if you don't have it (see the link in #tools)
- find the port number of the microbit
    - in the /dev folder a new file will be available after you plug in the microbit
    - the file name will start with "tty"
    - so go to the dev folder (cd /dev)
    - list the elements which start with "tty" (ls -l -a | grep tty)
    - try it when microbit is not connected and when is connected
    - find out which one is the new file
    - note that name, it is usually "ttyACM0"
- start screen on the serial port
    - type in "screen dev/_serial_port_name_comes_here 115200"
    - for exampe if the serial port is ttyACM0 "screen /dev/ttyACM0 115200"
    - you can now see that comes from the serial port
    - you can also send data if you type something in (but that wont be displayed on the screen!)
### Steps
- Setting up serial communication with micro:bit (mentor guidance)
  - usage of Serial blocks
  - usage of terminal software
- [Start the project of the week](https://github.com/greenfox-academy/teaching-materials/tree/master/project/hardware/microbit-binary-converter)
