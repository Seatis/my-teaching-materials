# Home automation peripheral devices

## Description
Several smart home peripheral devices which are based on the B-L475E-IOT01x board.
They can connect to the central device through the internet to provide data and to
receive control messages. The central device is created by an other project team.

The main goal is to
- design a software architecture and use it in different use-cases
- create a working devices where several developers collaborate
- reverse engineer

## Main features
- Common
  - Connects to the central device using the onboard WiFi module
    - WiFi AP mode for setup
    - WiFi STA mode for regular operation
  - Logging data to SD card if the network or the server in not available
- Weather station
  - Measures temperature
  - Measures relative humidity
  - Measures pressure
- Air conditioner controller
  - Controls the air conditioners in the classroom with infra-red technology
  - Communication protocol is reverse engineered
- Projector screen controller
  - Controls the project screen in the classroom with infra-red technology
  - Communication protocol is reverse engineered

## Technology
- Common
  - WiFi
  - STM32 HAL
  - SD card
- Weather station
  - STM32F7 BSP
- Air conditioner controller
  - IR
  - bit banging
- Projector screen controller
  - IR
  - bit banging
