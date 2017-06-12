# Introduction to STM32
*Learn how does the STM32 Iot microcontroller works*

## Objectives
- Know how to build a program to the STM32
- Understand the architecture of the microcontroller

## Materials & Resources
### Environment
  - Make sure that System Workbench for STM32 is installed on your machine (see [IDE-Installation-Guide](https://github.com/greenfox-academy/totoro-syllabus/blob/master/IDE-Installation-Guide.md) for further information)
  - Make sure that [STM32CubeL4 libary package](http://www.st.com/en/embedded-software/stm32cubel4.html) is installed on your machine
      - In the "GET SOFTWARE" section click on the "Get Software" button to download the package
      - An ST registration will be required
      - A .zip file will be downloaded, which contains a lot's of source files
      - Unzip it to a folder
      - You can version control that folder with GIT
          - Be sure not to push all the source code to you github account
          - It is an enormous amount of code, we will deal with it properly later

### Training

| Materials to read |
|:--------|
|[Embedded software engineering](https://www.linkedin.com/pulse/5-differences-between-embedded-maharajan)|
| [Getting started with STM32CubeL4 for STM32L4 Series](https://my.st.com/content/ccc/resource/technical/document/user_manual/74/09/3d/80/f9/39/4c/c7/DM00157440.pdf/files/DM00157440.pdf/jcr:content/translations/en.DM00157440.pdf)|
| [Embedded software](http://internetofthingsagenda.techtarget.com/definition/embedded-software)|

| Materials to watch | Duration |
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

## Material Review
### Microcontroller
#### Abstraction
- Meaning of abstarction
    - example from a [previous workshop](#)
- STM32CubeL4
    - Level 0
        - Low Layer (LL)
        - Core drivers
        - BSP Driver
        - Hardware Abstraction Layer (HAL)
    - Level 1
        - Middleware components
    - Level 2
        - Application

#### Embedded software
- What is it good for
- Usage in our class
- Real time operation

## Workshop
Before getting started with todays workshop, please have a look at  [this](https://github.com/greenfox-academy/teaching-materials/tree/hw-introduction-to-STM32_/workshop/hardware/Introduction-to-STM32/debugging)
