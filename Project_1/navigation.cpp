/*
 * navigation.cpp
 *
 * Created: 11/07/2013 10:24:44 p.m.
 *  Author: Liam & Josh
 */ 
#include "stdlib.h"
#include "config.h"
#include "math.h"

#include <avr/io.h>
#include "navigation.h"
#include "sensor.h"

#define PI 3.14159265

void NAVIGATION_update(void)
{
		
}

uint8_t NAVIGATION_getDistance(uint8_t current_location_x,uint8_t current_location_y, uint8_t next_WP_x,uint8_t next_WP_y)
{
	uint8_t distance;
	uint8_t side_one;
	uint8_t side_two;
	
// Need example of GPS output so can calculate length and width	
	side_one = abs(current_location_x - next_WP_x);
	side_two = abs(current_location_y - next_WP_y);
	
// Pythagoras theory a2 + b2 = c2 (absolute)
	distance = round(sqrt(pow(side_one, 2) + pow(side_two, 2)));
	return distance;
	
}

uint8_t NAVIGATION_getCurrentHeading(void)
{
	return SENSOR_HMC5883L_getHeading();
	
}




uint8_t NAVIGATION_getDirection(uint8_t current_location_x,uint8_t current_location_y, uint8_t next_WP_x,uint8_t next_WP_y)
{
	uint8_t angle;
	uint8_t adj;
	uint8_t hyp;
	
	// Need example of GPS output so can calculate length and width
	hyp = NAVIGATION_getDistance(current_location_x, current_location_y, next_WP_x, next_WP_y);
	adj = abs(current_location_y - next_WP_y);
		
	// Pythagoras theory angle cos a/h
	angle = round(acos(adj/hyp) * 180.0 / PI); // convert to degrees
	return angle;
}

uint8_t NAVIGATION_nextWaypoint(uint8_t current_waypoint)
{
	// find the next way point
	uint8_t next_waypoint = 0;
		
	switch (current_waypoint)
	{
		case WAYPOINT_1:
			next_waypoint = WAYPOINT_2;
			break;
		case WAYPOINT_2:
			next_waypoint = WAYPOINT_3;
			break;	
		case WAYPOINT_3:
			next_waypoint = WAYPOINT_4;	
			break;
		case WAYPOINT_4:
			next_waypoint = HOME;
			break;
	}
	
	return next_waypoint;
}


uint8_t NAVIGATION_getSteering(uint8_t target_heading, uint8_t current_heading)
{
	return 1;
}

uint8_t NAVIGATION_getSpeed(uint8_t turning_radius)
{
	return 1;
}

void NAVIGATION_setSteering(uint8_t turning_radius)
{
	
}

void NAVIGATION_setSpeed(uint8_t speed)
{
	/*
	//Test Code - PWM output used to dim a LED 
	uint8_t i = 0;
	while(1)
	{
		if (i<100)
	{
		i=i+1;
	}
		else
	{
		i = 0;
	}
	OCR1A = (i);
	_delay_ms(100);
	USART_transmit_packet(0x2b, 0x41);//@,A
	}
		*/	
}
