#include <avr/io.h>			// This header contains the definitions for the io registers
#include <stdint.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define F_CPU	16000000	// This definition tells to _delay_ms() that the CPU runs at 16MHz
#include <util/delay.h>		// This header contains the _delay_ms() function


#define RX_CIRC_BUFF_LEN 25
//TODO: Create the circular buffer with the length of RX_CIRC_BUFF_LEN
volatile char buffer[RX_CIRC_BUFF_LEN];
//TODO: Create the head pointer of the buffer
volatile char *rx_circ_buff_head;
//TODO: Create the tail pointer of the buffer
volatile char *rx_circ_buff_tail;
//TODO: Create the write pointer of the buffer
volatile char *rx_circ_buff_write_ptr;
//TODO: Create the read pointer of the buffer
volatile char *rx_circ_buff_read_ptr;


ISR(USART_RX_vect)
{
	//TODO:
	// Put received character into the circular buffer
	*rx_circ_buff_write_ptr = UDR0;

	//TODO:
	// Increment the write ptr
	// Be aware that the write ptr might point to the end of the buffer.
	// In this case you have to set it back to the start of the buffer
	if (rx_circ_buff_write_ptr == rx_circ_buff_tail)
		rx_circ_buff_write_ptr = rx_circ_buff_head;
	else
		rx_circ_buff_write_ptr++;
}

void UART_init()
{
	// Write this function
	// See the datasheet on page 246 for hints and table 25-9.

	// At first set the baud rate to 9600
	// The CPU clock frequency is 16MHz
	uint16_t ubbr = 103;
	UBRR0H = ubbr >> 8;
	UBRR0L = ubbr;

	// Set the following frame format: 8N1
	// It's set by default to 8N1

	// Enable TX
	UCSR0B |= 1 << TXEN0;

	// Enable RX
	UCSR0B |= 1 << RXEN0;

	// Enable RX interrupt
	UCSR0B |= 1 << RXCIE0;

	//TODO:
	// Initialize circular buffer pointers, they should point to the head of the buffer
	rx_circ_buff_head = &(buffer[0]);
	//TODO: Create the tail pointer of the buffer
	rx_circ_buff_tail = &(buffer[RX_CIRC_BUFF_LEN - 1]);
	//TODO: Create the write pointer of the buffer
	rx_circ_buff_write_ptr = rx_circ_buff_head;
	//TODO: Create the read pointer of the buffer
	rx_circ_buff_read_ptr = rx_circ_buff_head;
	// Enable interrupts globally
	sei();
}

void UART_send_character(char character)
{
	// Write this function, which can send a character through UART will polling method
	// See page 247 of the datasheet for hints, be aware that the code in the datasheet has a problem :)

	//TODO:
	// Wait for empty USART buffer register
	while ( !( UCSR0A & (1 << UDRE0)) );

	//TODO:
	// Put data to USART buffer register
	UDR0 = character;
}

char UART_get_character()
{
	//TODO:
	// Wait for data in the circular buffer, this can be detected if the write and read pointers are pointing to the same memory block
	while (rx_circ_buff_read_ptr == rx_circ_buff_write_ptr);

	//TODO:
	// Save the data to a temporary variable
	char to_return = *rx_circ_buff_read_ptr;

	//TODO:
	// Increment the read ptr
	// Be aware that the read ptr might point to the end of the buffer.
	// In this case you have to set it back to the start of the buffer
	if (rx_circ_buff_read_ptr == rx_circ_buff_tail)
		rx_circ_buff_read_ptr = rx_circ_buff_head;
	else
		rx_circ_buff_read_ptr++;

	//TODO:
	// Return the read character
	return to_return;
}

int main(void)
{
	char buffer[255];

	//Don't forget to call the init function :)
	UART_init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// Try printf
	printf("Startup...\r\n");

	// Loop that runs forever
	while (1) {
		// With gets and puts create a loopback, use the buffer variable!
		gets(buffer);
		_delay_ms(500);
		puts(buffer);
		_delay_ms(500);
	}
}