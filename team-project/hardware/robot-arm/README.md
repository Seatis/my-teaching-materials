# RobotArm

## Description

A 3 axis plotter robot arm, based on STM32F746G-DISCO. One teams work on this project.

The main goals are to:
- Can be used as regular robot arm
- Controlled by joint and xyz coordinates
- Can be used as a drawing machine


## Main features

- Robotarm (3-axis movement)
- Controlling servos
- Can be controlled with joint coordinates
- Can be controlled with xyz coordinates
- Reads data from serial port
- Reads data from SD card
- USB mass storage device
- Plotter functionality
- Understands G code
- Can be used as a 3D printer
- PI controlled filament heater and filament
- GUI
- WEB interface
- PC software (firmware upgrade, parameter setup)

## Technology


- CMSIS-OS (freeRTOS)
- STM32F7 HAL
- SD card
- Front-end
  - STM32 GUI framework
  - HTML
  - javascript
- Back-end
  - lwIP
