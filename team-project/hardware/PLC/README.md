# TOTORO PLC

## Description

A PLC-like system with PLC structure.

One teams work on this project.

The main goals are to:
- create a working system with the most used IO-s
- Choose and design proper backbus communication
- Proper task handling
- SQL data upload
- Use a real PLC at the end

## Main features

- Master board
- Slave IO functions:
	- DIN/DOUT board
	- AIN/AOUT board
	- PWM out/Freq meas board
- Proper backbus communication
- Proper task handling
- WEB interface
- SQL data upload
- GUI
- Design a minimalistic prog language
- Programing software on PC
- Reads program from SD card

## Technology

- Boards:
 - STM32F746G-DISCO
 - NUCLEO-L476RG
- CMSIS-OS (freeRTOS)
- STM32F7 HAL
- SD card
- SQL
- PLC programming
- lwIP
