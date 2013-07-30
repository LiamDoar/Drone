/*
 * twi.cpp
 *
 * Created: 10/07/2013 12:01:47 a.m.
 *  Author: Liam
 */ 
#include <avr/io.h>

void TWI_init(void)
{
	//set SCL to 400kHz
	TWSR = 0x00;
	TWBR = 0x0C;
	//enable TWI
	TWCR = (1<<TWEN);
}

void TWI_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
}
//send stop signal
void TWI_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void TWI_write(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
}
//read byte with ACK
uint8_t TWI_readACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	return TWDR;
}
//read byte with NACK
uint8_t TWI_readNACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	return TWDR;
}

uint8_t TWI_status(void)
{
	uint8_t status;
	//mask status
	status = TWSR & 0xF8;
	return status;
}

void TWI_complete(void)
{
	int i = 0;		//time out variable
	// wait for i2c interface to complete operation
	while ((!(TWCR & (1<<TWINT))) && (i < 90))
	i++;
	if (i>88);
	//Return error message here
}