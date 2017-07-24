# RobotArm

## Description

A 3 axis plotter robot arm, based on the STM32F746G-DISCO board. One team works on this project.

The main goals are:
- can be used as regular robot arm
- controlled by joint and xyz coordinates
- can be used as a drawing machine


## Main features
- robotarm (3-axis movement)
- controlling servos
- can be controlled with joint coordinates
- can be controlled with xyz coordinates
- reads data from serial port
- reads data from SD card
- USB mass storage device
- plotter functionality
- understands G code
- can be used as a 3D printer
- PI controlled filament heater and filament
- GUI
- WEB interface
- PC software (firmware upgrade, parameter setup)

## Technology
- CMSIS-OS (freeRTOS)
- STM32F7 HAL
- SD card
- front-end
  - STM32 GUI framework
  - HTML
  - javascript
- back-end
  - lwIP
