# TOTORO PLC

## Description

A PLC-like system with PLC structure. The Master(CPU) unit is a STM32F746G-DISCO board, the slaves are NUCLEO-L476RG. The Slaves are the I/O-s, the master is the brain. One team works on this project.

The main goals are to:
- Create a working system with the commonly used IO-s
- Choose and design proper backbus communication, task handling
- SQL data upload
- Use a real PLC at the end

## Main features

- Master board
- Slave IO functions:
	- DIN/DOUT board
	- AIN/AOUT board
	- PWM out/Freq measurement board
- Proper backbus communication
- Proper task handling
- WEB interface
- SQL data upload
- GUI
- Design a minimalistic programming language
- Programing software on PC
- Reads program from SD card

## Technology

- CMSIS-OS (freeRTOS)
- STM32F7 HAL
- STM32L4 HAL
- STM32 GUI framework
- SD card
- SQL
- PLC programming
- lwIP
- STM32 GUI framework
