# The lwIP library
*Create a socket server on the STM32F746G-DISCOVERY board*

## Objectives
- learn how to create and manage threads with CMSIS-OS
- create a socket server on an embedded platform

## Materials & Resources
### Environment
- Make sure that System Workbench for STM32 is installed on your machine
- Make sure that [STM32CubeF7 library package](https://my.st.com/content/my_st_com/en/products/embedded-software/mcus-embedded-software/stm32-embedded-software/stm32cube-embedded-software/stm32cubef7.license%3d1497432583192.html) is installed on your machine

### Training
| Material | Duration |
|:---------|-----:|
| [What is an Operating System as Fast As Possible](https://www.youtube.com/watch?v=pVzRTmdd9j0) | 5:15 |
| [Types of Operating Systems as Fast As Possible](https://www.youtube.com/watch?v=MR2ntdZW__A) | 5:42 |
| [freeRTOS fundamentals - Multitasking](http://www.freertos.org/implementation/a00004.html) | - |
| [freeRTOS fundamentals - Scheduling](http://www.freertos.org/implementation/a00005.html) | - |
| [freeRTOS fundamentals - Real Time Applications](http://www.freertos.org/implementation/a00007.html) | - |
| [freeRTOS fundamentals - Real Time Scheduling](http://www.freertos.org/implementation/a00008.html) | - |
| [What is the difference between real time operating system and non real time operating system?](https://www.quora.com/What-is-the-difference-between-real-time-operating-system-and-non-real-time-operating-system) | - |
| [CMSIS-RTOS - Generic RTOS Interface](http://www.keil.com/pack/doc/CMSIS/RTOS/html/genRTOSIF.html) | - |

The following material could be useful during the workshop, it is the reference of the CMSIS-RTOS functions.

| Material | Duration |
|:---------|-----:|
| [CMSIS-RTOS - Function Overview](http://www.keil.com/pack/doc/CMSIS/RTOS/html/functionOverview.html) | - |

## Material Review
### OS basics
- Why do we need them?
  - multitasking
  - memory management
- Real time vs Non real time
  - Scheduling determinacy
- Process vs Task vs Thread
  - these are just playing with words, but:
    - processes are running on different memory spaces
      - a process can have multiple threads
    - threads have the same shared memory
  - in the freeRTOS operating system terminology there are only **tasks**
    - and they use the **thread** expression as a synonym to **task**
    - in freeRTOS usually the memory is shared, so there is no memory protection
    - hence all running programs are using the same shared memory -> they are threads

### RTOS basics
- The scheduler
  - Fixed scheduling tick
  - Preemptive
  - Task priorities
- Tasks
  - A function which can do something
  - Priority can be assigned
  - The higher priority task runs on the CPU until it starts to wait for something
- Communication between Tasks
  - It is possible
  - We will learn about it later

### CMSIS-OS
- Based on freeRTOS
- It is a higher level abstraction on top of freeRTOS
- Creating tasks
  - osThreadDef()
  - osThreadCreate()
  - this will start the thread if the kernel is running
- Starting the OS
  - always create an initializer thread
    - create it before the kernel is started
    - always terminate the initializer thread at the end of initializing
      - osThreadTerminate()
  - osKernelStart() will start the scheduler
- Running tasks
  - the higher priority thread will run always, except if it
    - waits for another task with osWait()
    - waits for a specified time with osSleep()
  - always use osSleep() or osWait() in every task, or it will block other tasks

## Workshop
### Loading the templete onto the board
- Open the template project in System Workbench for STM32
- You have to set up the board's MAC address to a unique one
  - Open the `stm32f7xx_hal_conf.h` header file
  - Search for the following part:
    ```
    #define MAC_ADDR0   2U
    #define MAC_ADDR1   0U
    #define MAC_ADDR2   0U
    #define MAC_ADDR3   0U
    #define MAC_ADDR4   0U
    #define MAC_ADDR5   0U
    ```
  - Change the `#define MAC_ADDR5   0U` to a unique value
    - Open [this](https://docs.google.com/spreadsheets/d/112PZIwoXfJFBjqVzo8Tr5p_NQm1c0PQLqMVT_sh9W-c/edit#gid=0)
    file and search for your name
    - Use the row number of your name as the value of `#define MAC_ADDR5`
    - For example for `Veréb Szabolcs` the code would look like
    ```
    #define MAC_ADDR0   2U
    #define MAC_ADDR1   0U
    #define MAC_ADDR2   0U
    #define MAC_ADDR3   0U
    #define MAC_ADDR4   0U
    #define MAC_ADDR5   21U
    ```
- After that clean and build the project
- Program the board
- Connect the board to the network with an UTP cable
- Push the reset button on the board


- Set proper MAC address in hal_conf!
- Use the LCD_Log utility
  - function list...
-


## Solution
[Solution](#)
