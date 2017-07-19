# Oscilloscope

## Description
An advanced oscilloscope with 1MHz analog bandwidth based on the STM32F746G-DISCOVERY board.

The main goal is to
- design a software architecture which is able to process tons of data
- create a working device where several developers collaborate
- immerse into measurement technology

## Main features
- ADC sampling at 2.4MSPS
- Maximal input voltage with 1x probe
  - +20V in DC mode
  - +-10V in AC mode
- Multiple resolution settings
  - 1x, 2x, 4x, 5x, 8x, 10x, 16x, 32x amplification
- Timebase setting
- Trigger logic
- GUI
  - Displaying graph
  - Zooming
  - Screenshot to SD card
- Averaging mode
- Measurements
    - peak-to-peak
    - RMS
    - frequency
    - period

## Technology
- Common
  - CMSIS-OS (freeRTOS)
  - STM327F HAL
- Front-end
  - STM32 GUI framework
- Back-end
  - Internal ADC with DMA
  - Variable Gain Amplifier with SPI
  - external DAC
  - SD card
