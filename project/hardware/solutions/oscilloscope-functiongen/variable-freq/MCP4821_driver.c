#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "MCP4821_driver.h"

void MCP4821_init()
{
	// Initialize the SPI related pins. Use the definitions from MCP4821_driver.h!
	SPI_MOSI_DDR |= 1 << SPI_MOSI_DDR_POS;
	SPI_SCK_DDR |= 1 << SPI_SCK_DDR_POS;
	SPI_SS_DDR |= 1 << SPI_SS_DDR_POS;

	// Pull SS pin to high!
	SPI_SS_PORT |= 1 << SPI_SS_PORT_POS;

	// Set the SPI mode (CPOL and CPHA). Use the definitions from MCP4821_driver.h!
	if (SPI_CPOL == 1) {
		SPCR |= 1 << CPOL;
	}
	if (SPI_CPHA == 1) {
		SPCR |= 1 << CPHA;
	}

	// Set master mode
	SPCR |= 1 << MSTR;

	// Set the clock frequency. Use the definitions from MCP4821_driver.h!
	SPCR |= SPI_SPR;

	// Enable SPI peripheral
	SPCR |= 1 << SPE;
}

void MCP4821_send_raw_data(uint16_t data)
{
	// Pull SS low
	SPI_SS_PORT &= ~(1 << SPI_SS_PORT_POS);

	// Put the top 8bits of the data to the SPI shift register
	SPDR = data >> 8;

	// Wait for the end of the transmission
	while (!(SPSR & (1 << SPIF) ));
	// You have to read the SPDR register to clear the SPIF flag after the end of transmission
	volatile uint8_t dummy_variable = SPDR;

	// Put the bottom 8bits of the data to the SPI shift register
	SPDR = data;

	// Wait for the end of the transmission
	while (!(SPSR & (1 << SPIF) ));
	// You have to read the SPDR register to clear the SPIF flag after the end of transmission
	dummy_variable = SPDR;

	// Pull SS high
	SPI_SS_PORT |= (1 << SPI_SS_PORT_POS);
}

void MCP4821_send_data(MCP4821_data_t *data)
{
	// Write this function!
	// Try to convert the data variable to a 16bit number with memcpy()
	// Then use the MCP4821_SendRawData() function to send the data
	uint16_t buffer;
	memcpy(&buffer, data, sizeof(MCP4821_data_t));
	MCP4821_send_raw_data(buffer);
}
