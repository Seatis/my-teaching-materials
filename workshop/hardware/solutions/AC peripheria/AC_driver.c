#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "AC_driver.h"
#include <avr/interrupt.h>

void TWIInit(void)
{
	// TODO:
	// Set Prescaler to 4
	//TWSR = 0x01;
	DDRB |= 1 << PORTB5;
	// Disable the digital input buffers.
	DIDR1 = (1<<AIN1D) | (1<<AIN0D);
	
	ACSRB |= 1 << ACOE;		//When this bit is set, the analog comparator output is connected to the ACO pin.
	/*DDRA&=~(1<<AIN0);//as input
	DDRA&=~(1<<AIN1);//as input
	PORTA&=~(1<<AIN0);//no Pull-up
	PORTA&=~(1<<AIN1);//no Pull-up
	DDRB|=(1<<PORTB5); //Led pin as output
	//PORTD|=(1<<LED);//Initally LED is OFF
	//SFIOR|=(1<<ACME);//enable multiplexer
	ADCSRA&=~(1<<ADEN);//make sure ADC is OFF*/
//	ADMUX|=(0<<MUX2)|(1<<MUX1)|(1<<MUX0); //select ADC3 as negative AIN
	ACSR|=
	(0<<ACD)|	//Comparator ON
	(0<<ACBG)|	//Connect reference to AIN0
	(1<<ACO)|	//AC directly connected to ACO
	(0<<ACIE)|	//Comparator Interrupt enable
	(1<<ACIC)|	//input capture enabled
	(0<<ACIS1)| //set interrupt on output toggle
	(0<<ACIS0);
		//TIMER INIT		TCCR1B |=1<< ICNC1;		// TC0 INIT

	// Clock init
	TCCR1B |= 1 << CS12;
	TCCR1B &= ~(1 << CS11);
	TCCR1B |= 1 << CS00;
/*	TCCR1B |= 1 << WGM13;	TCCR1B |= 1 << WGM12;	TCCR1A &= ~(1 << WGM11);	TCCR1A &= ~(1 << WGM10);
	ICR1=0xFFFF;*/

	// Enable ICIE1 interrupt
	TIMSK1 |= 1 << ICIE1;
}

uint16_t timer1_Read16( void )
{
	//unsigned char sreg;
	uint16_t i;
	/* Save global interrupt flag */
	//sreg = SREG;
	/* Disable interrupts */
	//cli();
	/* Read TCNT1 into i */
	i = ICR1;
	/* Restore global interrupt flag */
	//SREG = sreg;
	//sei();
	return i;
}

void TWIStart(void)
{
	//TODO
	//Send start signal
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	
	// TODO:
	// Wait for TWINT Flag set. This indicates that
	//the START condition has been transmitted.	while ((TWCR & (1<<TWINT)) == 0);
}

void TWIStop(void)
{
	//TODO
	//Send stop signal
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

uint8_t TWIReadACK(void)
{
	//TODO
	//Read byte with ACK
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}


uint8_t TWIReadNACK(void)
{
	//TODO
	//Read byte with NACK
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}

void TWIWrite(uint8_t u8data)
{
	//TODO
	//Load DATA into TWDR Register. Clear TWINT
	//bit in TWCR to start transmission of data. 
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	TWDR = u8data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}

//TODO
//Write a function that communicates with the TC74A0. 
//datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf
//And returns with the temperature.

uint8_t read_temp (uint8_t address){

	TWIStart();
	TWIWrite(address << TWA0 | TC_WRITE << TWGCE);
	TWIWrite(0);
	TWIStart();
	TWIWrite(address << TWA0 | TC_READ << TWGCE);
	uint8_t ii = TWIReadNACK();
	TWIStop();
	
	return ii;
}

//TODO Advanced:
//Calculate the average of the last 16 data, and returns with that.
//TODO Advanced+: 
//Select the outstanding (false data) before average it.
//These data don't needed, mess up your datas, get rid of it.
