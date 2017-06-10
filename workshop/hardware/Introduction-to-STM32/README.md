# Introduction to STM32
*Learn how does the STM32 Iot microcontroller works*

## Objectives
- Know how to build a program to the STM32
- Understand the architecture of the microcontroller

## Materials & Resources
### Environment
  - Make sure that System Workbench for STM32 is installed on your machine (see [IDE-Installation-Guide](https://github.com/greenfox-academy/totoro-syllabus/blob/master/IDE-Installation-Guide.md) for further information)
  - Make sure that [STM32CubeL4 libary package](http://www.st.com/en/embedded-software/stm32cubel4.html) is installed on your machine

### Training
#### STM32 programming
##### Basic

| Material to read |
|:--------:|
| [Getting started with the STM32 board](http://www.st.com/content/ccc/resource/technical/document/user_manual/47/af/1e/94/ef/a2/49/e6/DM00180213.pdf/files/DM00180213.pdf/jcr:content/translations/en.DM00180213.pdf)|
| [Embedded software](https://www.youtube.com/watch?v=Va8c9g3NclA)|
Notice that the article is for an other board, try to understand the core things.

| Material to watch | Duration |
|:---------|-----:|
| [Dive into abstraction](https://www.youtube.com/watch?v=X8QSymRlEEY)| 5:27 |
| [Hardware abstraction layer](https://www.youtube.com/watch?v=Va8c9g3NclA)| 9:58 |


A short specification about the STM32 board :
- Core: ARM® 32-bit Cortex®-M4 CPU with FPU
- 1 MB Flash
- 128 KB of SRAM
- USB OTG 2.0
- Bluetooth® V4.1 module
- Sub-GHz RF module
- Wi-Fi® module
- NFC tag
- Digital omnidirectional microphones
- Capacitive digital sensor for relative humidity and temperature
- 3-axis magnetometer
- 3D accelerometer and 3D gyroscope
- Absolute digital output barometer
- 2 push-buttons

| If you have some free time |
|:---------|-----:|
| [Embedded software engineering vs. software development](https://www.linkedin.com/pulse/5-differences-between-embedded-maharajan)|



## Material Review
### Microcontroller
#### Abstraction
- Meaning of abstarction
    - example in a C code
- Microcontroller
    - BSP Driver
    - Low Layer (LL)
    - Core drivers
    - hardware absztaction layer (HAL)
    - Middleware components

#### Embedded software
- What is it good for
- Usage in our class

## Workshop
