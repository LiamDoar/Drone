/*
 * navigation.h
 *
 * Created: 11/07/2013 11:25:08 p.m.
 *  Author: Liam
 */ 


#ifndef NAVIGATION_H_
#define NAVIGATION_H_

void NAVIGATION_update(void);
uint8_t NAVIGATION_getDistance(uint8_t current_location, uint8_t next_WP);
uint8_t NAVIGATION_getDirection(uint8_t current_location, uint8_t next_WP);
uint8_t NAVIGATION_getCurrentHeading(void);
uint8_t NAVIGATION_nextWaypoint(uint8_t current_waypoint);

uint8_t NAVIGATION_getSteering(uint8_t target_heading, uint8_t current_heading);
uint8_t NAVIGATION_getSpeed(uint8_t turning_radius);

void NAVIGATION_setSteering(uint8_t turning_radius);
void NAVIGATION_setSpeed(uint8_t speed);


#endif /* NAVIGATION_H_ */