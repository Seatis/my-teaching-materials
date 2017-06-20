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
|[32F746GDISCOVERY databrief](http://www.st.com/content/ccc/resource/technical/document/data_brief/b3/48/2b/e3/d2/12/45/c1/DM00179227.pdf/files/DM00179227.pdf/jcr:content/translations/en.DM00179227.pdf)| - |
|[32F746GDISCOVERY user manual](http://www.st.com/content/ccc/resource/technical/document/user_manual/f0/14/c1/b9/95/6d/40/4d/DM00190424.pdf/files/DM00190424.pdf/jcr:content/translations/en.DM00190424.pdf)|-|
|[Embedded software engineering](https://www.linkedin.com/pulse/5-differences-between-embedded-maharajan)|-|
| [Embedded software](http://internetofthingsagenda.techtarget.com/definition/embedded-software)|-|
| [Dive into abstraction](https://www.youtube.com/watch?v=X8QSymRlEEY)| 5:27 |
| [Hardware abstraction layer](https://www.youtube.com/watch?v=Va8c9g3NclA)| 9:58 |
| [Getting started with STM32CubeF7 firmware package](http://www.st.com/content/ccc/resource/technical/document/user_manual/47/af/1e/94/ef/a2/49/e6/DM00180213.pdf/files/DM00180213.pdf/jcr:content/translations/en.DM00180213.pdf)|-|
| [Application note - STM32Cube firmware examples for STM32F7 Series](http://www.st.com/content/ccc/resource/technical/document/application_note/83/72/1e/52/2b/de/4c/7e/DM00210367.pdf/files/DM00210367.pdf/jcr:content/translations/en.DM00210367.pdf)|-|

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
- copy the [following "Projects" folder](workshop) into the CubeF7 root folder
    - there should already be a "Projects" folder in that root folder
    - there won't be any overwriting issues, don't be afraid
- open the SWSTM32 IDE
- "File"->"Open Projects from File System"
- In the "Import source" cell enter ```YOUR_CUBEF7_ROOT_PATH\Projects\STM32746G-Discovery\GreenFox\led_blinker\SW4STM32\STM32746G_Discovery_led_blinker```
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
Now that your SWSTM32 environment is working correctly let's start to dive into
the world of the CubeF7 software package!

Modify the previously loaded project: make a LED blinker! If you don't know where
to start, take a look at the BSP of the STM32F746G-DISCOVERY board.

### Pushbutton handling
In the [Setting up the environment](#setting-up-the-environment) section
you copied another template project, which is located in `Projects\STM32746G-Discovery\GreenFox\push_button\SW4STM32\STM32746G_Discovery_push_button`.

Open this project in SWSTM32, and modify the code! The task is to make the LED lit
if the user pushbutton is pressed. If the button is not pressed, the LED should not
be lit.

### UART on STM32
In the [Setting up the environment](#setting-up-the-environment) section
you copied another template project, which is located in `Projects\STM32746G-Discovery\GreenFox\uart\SW4STM32\STM32746G_Discovery_uart`.

Open this project in SWSTM32, and modify the code! The COM1 port of the board should
be initialized. The goal is to be able to send data through UART to a PC terminal program.
You should try out the HAL UART functions, but `printf()` should work too.

### Basic LCD usage
In the [Setting up the environment](#setting-up-the-environment) section
you copied another template project, which is located in `Projects\STM32746G-Discovery\GreenFox\lcd_basic\SW4STM32\STM32746G_Discovery_lcd_basic`.

Open this project in SWSTM32, and modify the code! Try to print
out strings on the LCD, play around with the BSP LCD functions (strings, basic shapes, colors, etc.).

##Solution
[Solution](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/hardware/solutions/stm32-introduction)
