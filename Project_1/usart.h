/*
 * IncFile1.h
 *
 * Created: 3/07/2013 12:29:51 a.m.
 *  Author: Liam
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_


void USART_init (void);
void USART_transmit_char(unsigned char data);
void USART_transmit_string(const char* txData);
void USART_transmit_packet(uint8_t addr, uint8_t cmd);
unsigned char USART_receive( void );


#endif /* INCFILE1_H_ */