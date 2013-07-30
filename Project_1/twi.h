/*
 * twi.h
 *
 * Created: 10/07/2013 12:02:13 a.m.
 *  Author: Liam
 */ 


#ifndef TWI_H_
#define TWI_H_

void TWI_init(void);
void TWI_start(void);
void TWI_stop(void);
void TWI_complete(void);
void TWI_write(uint8_t data);
uint8_t TWI_readACK(void);
uint8_t TWI_readNACK(void);
uint8_t TWI_status(void);


#endif /* TWI_H_ */