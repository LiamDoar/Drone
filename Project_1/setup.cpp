/*
 * SETUP.cpp
 *
 * Created: 3/07/2013 10:44:39 a.m.
 *  Author: Liam
 */ 
#include <avr/io.h>
#include "config.h"


void SETUP_timer0(void) // setup timer 0
{
	TCCR0B |= (1 << CS00); //no pre-scaller
	
	TCNT0 = 0;
}

void SETUP_pwm_init(void) // setup timer 1 for fast PWM
{
	TCCR1A |= (1 << WGM11)|(1 << COM1A1);
	TCCR1B |= (1 << WGM12)|(1 << WGM13)|(1 << CS10);
	ICR1 = TIMER1_TOP;
}

void SETUP_port_init(void) // setup port functions (input / output)
{
	//All of port B set as outputs
	DDRB = 0xff; 
}
