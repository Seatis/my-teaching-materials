# Home automation central controller

## Description
A smart home central controller which is based on the STM32F746G-DISCOVERY board.
Several peripheral devices can connect to it through the local network. The
peripheral devices are created by an other project team.

The main goal is to
- design a software architecture
- create a working device where several developers collaborate
- use high level of security

## Main features
- Detects peripherals on the network
- Runs a server which is able to receive data from the peripherals
- Saves incoming data to SD card
- Provides WEB interface (SD card as storage)
- Provides GUI interface (SD card as storage if needed)
- Provides secure WEB access
- Provides multiple user access
- Users can log in with RDIF tags
- Users have different permissions (unix like)

## Technology
- Common
  - CMSIS-OS (freeRTOS)
  - STM32F7 HAL
- Front-end
  - STM32 GUI framework
  - HTML
  - javascript
- Back-end
  - lwIP
  - openSSL (wolfSSL)
  - MIFARE RFID
