/*
 * config.h
 *
 * Created: 10/07/2013 11:41:26 a.m.
 *  Author: Liam
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#define F_CPU 16000000UL  //16MHz as per the crystal on the prototype boards

//Timer0 8bit - used for schedules
#define TIMER0_FREQ 100000
#define TIMER0_PRESCALE 1
#define TIMER0_TOP = 155 //((F_CPU / (TIMER0_FREQ * TIMER0_PRESCALE)) - 1) //should be 155 for 10ms

//Timer1 16bit - used for servos output
#define TIMER1_FREQ 100000 // will depend on the servos used
#define TIMER1_PRESCALE 1
#define TIMER1_TOP ((F_CPU / (TIMER1_FREQ * TIMER1_PRESCALE)) - 1)

//USART
#define USART_BAUDRATE 9600 // Serial Speed
#define BAUD_PRESCALE ((F_CPU / USART_BAUDRATE/16UL) - 1) // only works when F_CPU*2 not sure why
#define BASE_ADDRESS 0x42 //address for base station
#define SYNC 0xAA// sync signal

// Sensor I2C address
#define HMC5883L_WRITE_ADDRESS 0x3C // write address
#define HMC5883L_READ_ADDRESS 0x3D // read address

//Way points - will need to be dynamic
#define WAYPOINT_1 10
#define WAYPOINT_2 20
#define WAYPOINT_3 30
#define WAYPOINT_4 40
#define HOME 50
#define WAYPOINT_ERROR 1

//speed - percentage
#define SPEED_MAX 100
#define SPEED_Min 30
#define SPEED_MAX_RADIUS 30 //degrees


#endif /* CONFIG_H_ */