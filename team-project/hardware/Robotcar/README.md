# RobotCar

## Description

Create a self-driving car, with a bunch of sensors and tune the car to get better and better. The main board will be a STM32F746G-DISCO, the secondary sensor and communication board a B-L475E-IOT01A. One teams work on this project.

The main goals are to:
- Follow a track (line)
- Implement proper motor control
- Get familiar with Matlab
- Log data and do telemetry

## Main features


- Servo steering control
- PI torque control of driver motor
- MATLAB motor model and controller parameters
- Line following
- Collision avoidance
- Plotting data onto the LCD
- Logging onto SD card
- USB mass storage device
- Telemetry on WebServer
- 3D vision based control

## Technology

- CMSIS-OS (freeRTOS)
- STM32F7 HAL
- STM32L4 HAL
- STM32 GUI framework
- SD card
- lwIP
- Matlab
