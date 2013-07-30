/*
 * Project_1.cpp
 *
 * Created: 2/07/2013 10:08:23 p.m.
 *  Author: Liam
 */ 
#include "config.h" // must run first to define global constants

#include <avr/io.h>
#include <util/delay.h> //needed for delay function.... not sure if needed for final code
#include <avr/interrupt.h> // required for interrupts 
#include "usart.h"  //Everything required for serial communications
#include "setup.h" //to setup all outputs, inputs, PWM, etc
#include "twi.h"
#include "sensor.h" //sensor.....
#include "navigation.h" //navigation....
#include "nmea.h" //


// global variables
//used for interrupts
uint8_t usart_buffer[80];
uint8_t nmea_count = 0; 
uint8_t nmea_message = 0;

//declaring functions that are within project.cpp
void fast_loop(void);
void medium_loop(void);
void slow_loop(void);

int main(void) // main function
{
	// setup USART
	USART_init();
	// Set Port pins
	SETUP_port_init();
	// setup PWM timer1
	SETUP_pwm_init();
	// setup timer0
	SETUP_timer0();
	// setup TWI
	TWI_init();
	// setup compass
	SENSOR_HMC5883L_init();
	// setup pressure sensor - not needed
	SENSOR_MS5611_init();
	// setup 3-axis tilt sensor - not needed
	SENSOR_xxxx_init();
	// setup GPS
//	SENSOR_GPS_init();
	
	NMEA_getUTC();
	
	// error code transmitted - USART_transmit_packet(BASE_ADDRESS, speed);
	uint8_t waypoint = 0;
	uint8_t counter = 0;
	uint8_t current_location = 0;
	uint8_t target_heading = 0;
	uint8_t waypoint_distance = 0;
	uint8_t current_heading = 0;
	uint8_t target_speed = 0;
	uint8_t gps_error = 0;
	uint8_t turning_radius = 0;
	
	
	while(1)// endless loop
    {
     	
		counter ++;
		
		current_location = SENSOR_GPS_getLocation();
			
		// do not navigate with corrupt data
		if (!(SENSOR_GPS_locationCheck(current_location)))
			
		{
			// waypoint distance
			waypoint_distance = NAVIGATION_getDistance(current_location, waypoint);
		
			// target_bearing is where we should be heading
			target_heading = NAVIGATION_getDirection(current_location, waypoint);
		}
		
		// if within error move to next way point
		if (waypoint_distance<WAYPOINT_ERROR)
		{
			waypoint = NAVIGATION_nextWaypoint(waypoint);
		}
				
		// current bearing
		current_heading = NAVIGATION_getCurrentHeading();
		
		//find steering... might be better to break it out into setsteering and getradius for data logging and fault finding
		turning_radius = NAVIGATION_getSteering(target_heading, current_heading);
		
		//set speed due to way point distance.... not sure if needed.
		//find speed due to turning radius. need to stop on last waypoint
		target_speed = NAVIGATION_getSpeed(turning_radius);
		
		NAVIGATION_setSpeed(target_speed);
		NAVIGATION_setSteering(turning_radius);
			
		// 1hz loop... 1s = (100 * 0.01)
		/*if (counter >= 200)
		{
			USART_transmit_packet(BASE_ADDRESS, 0x01);
			counter = 0;
		}
		*/
		
		
		
		// $GPGGA,230600.501,4543.8895,N,02112.7238,E,1,03,3.3,96.7,M,39.0,M,,0000*6A
		char ReceivedByte;
			for (;;) // Loop forever
			{
				while ((UCSR0A & (1 << RXC0)) == 0) {}; // Do nothing until data have been received and is ready to be read from UDR
				ReceivedByte = UDR0; // Fetch the received byte value into the variable "ByteReceived"

				while ((UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready for more data to be written to it
				UDR0 = ReceivedByte; // Echo back the received byte back to the computer
			}
		
		
		
		
		
		
		 
	}
}

/*ISR(USART_RX_vect)
{
	uint8_t data = UDR0;

	// might be better to use a switch statement
	// find the start of the string
	
	USART_transmit_packet(BASE_ADDRESS, data);
	/*
	if (data == '$')
	{
		nmea_message = 2; // 2 - in progress
		nmea_count = 0;
	}
	// find the end of the string
	else if (data == '\n')
	{
		nmea_message = 1; // 1 - usart_buffer ready to read
	}
	
	usart_buffer[nmea_count++] = data;
	

};

*/