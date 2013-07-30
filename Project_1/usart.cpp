/*
 * CPPFile1.cpp
 *
 * Created: 3/07/2013 12:21:43 a.m.
 *  Author: Liam
 */ 

#include <avr/io.h>
#include "config.h"


void USART_init(void)
{
	// Set baud rate
	UBRR0H = (unsigned char)(BAUD_PRESCALE>>8);
	UBRR0L = (unsigned char)BAUD_PRESCALE;
	// Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	// Set frame format: 8N1
	UCSR0C = ((1<<UCSZ00)|(1<<UCSZ01));
	
}

//void USART_transmit_char( unsigned char data )
void USART_transmit_char( unsigned char data )
{
	// Wait for empty transmit buffer
	while ( !( UCSR0A & (1<<UDRE0)) );
	// Put data into buffer, sends the data
	UDR0 = data;
}

// USART_Transmit_String is for testing purpose. Transmit_Package will work better
void USART_transmit_string(const char* data)
{
	int i = 0;
	
	// While not end of transmit string
	while(data[i] != '\0')
	{
		// Print string one char at a time
		USART_transmit_char(data[i]);
		// Increment char position in string
		i++;
	}
	
	/*
	int main()
	{
		char msg[] = "0123456789";
		int i;
		usart_init();
		while(1) {
			for(i = 0; msg[i]; i++)
			//usart_putchar(i);
			usart_putchar(msg[i]);
		}

	*/
}

void USART_transmit_packet(uint8_t addr, uint8_t cmd)
{
	//USART_transmit_char(SYNC); //send synchro byte
	//USART_transmit_char(addr); //send receiver address
	USART_transmit_char(cmd); //send increment command
	//USART_transmit_char((addr+cmd)); //send checksum
}

unsigned char USART_receive( void )
{
	// Wait for data to be received
	while ( !(UCSR0A & (1<<RXC0)) );
	// Get and return received data from buffer
	return UDR0;
}

