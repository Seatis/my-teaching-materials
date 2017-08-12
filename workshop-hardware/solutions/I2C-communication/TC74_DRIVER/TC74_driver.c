#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "TC74_driver.h"

void TWI_init(void)
{
	// TODO:
	// Set Prescaler to 4
	TWSR = 0x01;

	// TODO:
	// Set SCL frequency = 16000000 / (16 + 2 * 48 * 4) = 40kHz
	//So set the correct register to 0x30
	TWBR = 0x30;

	// TODO
	//Enable TWI
	TWCR = (1 << TWEN);
}

void TWI_start(void)
{
	//TODO
	//Send start signal
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	// TODO:
	// Wait for TWINT Flag set. This indicates that
	//the START condition has been transmitted.
	while ((TWCR & (1 << TWINT)) == 0);
}

void TWI_stop(void)
{
	//TODO
	//Send stop signal
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

uint8_t TWI_read_ack(void)
{
	//TODO
	//Read byte with ACK
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while ((TWCR & (1 << TWINT)) == 0);
	return TWDR;
}


uint8_t TWI_read_nack(void)
{
	//TODO
	//Read byte with NACK
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	TWCR = (1 << TWINT) | (1 << TWEN);
	while ((TWCR & (1 << TWINT)) == 0);
	return TWDR;
}

void TWI_write(uint8_t u8data)
{
	//TODO
	//Load DATA into TWDR Register. Clear TWINT
	//bit in TWCR to start transmission of data.
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	TWDR = u8data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while ((TWCR & (1 << TWINT)) == 0);
}

//TODO
//Write a function that communicates with the TC74A0.
//datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf
//And returns with the temperature.

uint8_t read_temp (uint8_t address)
{

	TWI_start();
	TWI_write(address << TWA0 | TC_WRITE << TWGCE);
	TWI_write(0);
	TWI_start();
	TWI_write(address << TWA0 | TC_READ << TWGCE);
	uint8_t ii = TWI_read_nack();
	TWI_stop();

	return ii;
}

//TODO Advanced:
//Calculate the average of the last 16 data, and returns with that.
//TODO Advanced+:
//Select the outstanding (false data) before average it.
//These data don't needed, mess up your datas, get rid of it.
