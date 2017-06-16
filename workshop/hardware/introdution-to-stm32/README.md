# Introduction to STM32
*Learn how does the STM32 Iot microcontroller works*

## Objectives
- Know how to build a program to the STM32
- Understand the architecture of the microcontroller

## Materials & Resources
### Environment
  - Make sure that System Workbench for STM32 is installed on your machine
    - [IDE-Installation-Guide](https://github.com/greenfox-academy/totoro-syllabus/blob/master/IDE-Installation-Guide.md)
  - Make sure that [STM32CubeF7 library package](https://my.st.com/content/my_st_com/en/products/embedded-software/mcus-embedded-software/stm32-embedded-software/stm32cube-embedded-software/stm32cubef7.license%3d1497432583192.html) is installed on your machine
      - In the "GET SOFTWARE" section click on the "Get Software" button to download the package
      - An ST registration will be required
      - A .zip file will be downloaded, which contains a lot's of source files
      - Unzip it to a folder
      - You can version control that folder with GIT
          - Be sure not to push all the source code to your github account
          - It is an enormous amount of code, we will deal with it properly later

### Training
We are going to use the [32F746GDISCOVERY    kit](http://www.st.com/en/evaluation-tools/32f746gdiscovery.html). It was built
around the STM32F746NGH6 microcontroller. Watch and/or read the following materials!

| Material | Duration |
|:---------|-----:|
|[Embedded software engineering](https://www.linkedin.com/pulse/5-differences-between-embedded-maharajan)|-|
| [Embedded software](http://internetofthingsagenda.techtarget.com/definition/embedded-software)|-|
| [Dive into abstraction](https://www.youtube.com/watch?v=X8QSymRlEEY)| 5:27 |
| [Hardware abstraction layer](https://www.youtube.com/watch?v=Va8c9g3NclA)| 9:58 |
| [Getting started with STM32CubeL4 for STM32L4 Series](https://my.st.com/content/ccc/resource/technical/document/user_manual/74/09/3d/80/f9/39/4c/c7/DM00157440.pdf/files/DM00157440.pdf/jcr:content/translations/en.DM00157440.pdf)|-|
|[32F746GDISCOVERY kit user manual](http://www.st.com/content/ccc/resource/technical/document/user_manual/f0/14/c1/b9/95/6d/40/4d/DM00190424.pdf/files/DM00190424.pdf/jcr:content/translations/en.DM00190424.pdf)|-|

Difference between the ATmega168PB and the STM32F746NGH6 MCU:

| Parameter | ATmega168PB | STM32F746NGH6 |
|-----------|-------------|---------------|
| Vcc | 1.8V – 5.5V | 1.71V - 3.6V |
| Max. clock speed | 20MHz | 216MHz |
| RAM | 1kB | 320kB |
| FLASH | 16kB | 1MB |
| ADC | 1x10bitx8ch | 3x12bitx24ch |
| Timers | 2x8bit, 1x16bit| 2x16bit motor control TMR, 10x16bit, 2x32bit |
| RTC | 1x | 1x |
| PWM | 6ch | many |
| USART | 1x | 4x|
| SPI | 1x | 6x |
| I2C | 1x | 4x |
| AC | 1x | - |

More STM32F746NGH6 features:
- 2xUSB
- TFT LCD controller
- HDMI-CEC
- 3xI^S
- Camera interface
- Ethernet
- 2xCAN
- 1xSDMMC
- LIN, smartcard, IrDA, modem control
- 2xSAI
- SPDIF input x4
- floating point unit
- DMA
- True random number generator

## Material Review
### Abstraction
- Meaning of abstarction
    - example from a [previous workshop](#)
- STM32CubeF7
    - Level 0
        - Low Layer (LL)
        - Core drivers
        - BSP Driver
        - Hardware Abstraction Layer (HAL)
    - Level 1
        - Middleware components
    - Level 2
        - Application

### Embedded software
- What is it good for
- Usage in our class
- Real time operation

### System Workbench for STM32 and CubeL4
- opening an existing project
- how to set up parallel building
- how to build, run, debug in the IDE
- how to use the provided workshop source files
- how to GIT this

## Workshop
### Setting up the environment
- unzip the CubeF7 to a folder
- copy the [following "Projects" folder] into the CubeF7 root folder
    - there should already be a "Projects" folder in that root folder
    - there won't be any overwriting issues, don't be afraid
- open the SWSTM32 IDE
- "File"->"Open Projects from File System"
- In the "Import source" cell enter ```YOUR_CUBEF7_ROOT_PATH\Projects\STM32746G-Discovery\led_blinker\SW4STM32\STM32746G_Discovery_led_blinker```
- Click on finish
- The selected project will appear on the left side of the screen in the "Project Explorer"
- Build the project
    - Right click on the project in the "Project Explorer"
    - Select "Clean project"
    - After the process ends right click again
    - Select "Build project"
    - A quite long process will start, be patient
- Run the project
    - with `Ctrl+F5`
    - or with `Run`->`Run`
- The green LED should be lit on your board

### LED blinker


### Pushbutton handling
### UART on STM32
