#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "MCP4821_driver.h"

void MCP4821_Init() {
    // TODO:
    // Initialize the SPI related pins. Use the definitions from MCP4821_driver.h!

    // TODO:
    // Pull SS pin to high!

    // TODO:
    // Set the SPI mode (CPOL and CPHA). Use the definitions from MCP4821_driver.h!

    // TODO:
    // Set master mode

    // TODO:
    // Set the clock frequency. Use the definitions from MCP4821_driver.h!

    // TODO:
    // Enable SPI peripheral
}

void MCP4821_SendRawData(uint16_t data) {
    // TODO:
    // Pull SS low

    // TODO:
    // Put the top 8bits of the data to the SPI shift register

    // TODO:
    // Wait for the end of the transmission

    // You have to read the SPDR register to clear the SPIF flag after the end of transmission
    volatile uint8_t dummy_variable = SPDR;

    // TODO:
    // Put the bottom 8bits of the data to the SPI shift register

    // TODO:
    // Wait for the end of the transmission

    // You have to read the SPDR register to clear the SPIF flag after the end of transmission
    dummy_variable = SPDR;

    // TODO:
    // Pull SS high
}

void MCP4821_SendData(MCP4821_Data_t* data) {
    // Convert the data variable to a 16bit number with memcpy()
    // Then use the MCP4821_SendRawData() function to send the data
    uint16_t buffer;
    memcpy(&buffer, data, sizeof(MCP4821_Data_t));
    MCP4821_SendRawData(buffer);
}
