/*
 * sensor.cpp
 *
 * Created: 10/07/2013 5:32:02 p.m.
 *  Author: Liam
 */ 

#include <avr/io.h>
#include <math.h>
#include "config.h"
#include "twi.h"
#include "usart.h"

void SENSOR_HMC5883L_init(void)
{
	TWI_start();
	TWI_complete();
	TWI_write(0x00);// set pointer to CRA
	TWI_complete();
	TWI_write(0x70);// write 0x70 to CRA
	TWI_complete();
	TWI_stop();
	
	TWI_start();
	TWI_complete();
	TWI_write(0x01);// set pointer to CRB
	TWI_complete();
	TWI_write(0xA0);// write 0xA0 to CRB
	TWI_complete();
	TWI_stop();

	TWI_start();
	TWI_complete();
	TWI_write(0x02);// set pointer to ??
	TWI_complete();
	TWI_write(0x00);// write 0x00 to allow continues monitoring
	TWI_complete();
	TWI_stop();
}

float SENSOR_HMC5883L_getHeading(void)
{
	int16_t raw_x = 0;
	int16_t raw_y = 0;
	int16_t raw_z = 0;
	float headingDegrees = 0;
	
	//set the pointer to the x axis
	TWI_start();
	TWI_complete();
	TWI_write(HMC5883L_WRITE_ADDRESS);
	TWI_complete();
	TWI_write(0x03); 
	TWI_complete();
	TWI_stop();
	
	//read data from x, y and z axis
	TWI_start();
	TWI_complete();
	TWI_write(HMC5883L_READ_ADDRESS);
	TWI_complete();
	raw_x = TWI_readACK(); 
	TWI_complete();
	raw_z = TWI_readACK();
	TWI_complete();
	raw_y = TWI_readACK();
	TWI_complete();
	TWI_stop();

	// convert the raw data into a heading in degrees
	headingDegrees = atan2((double)raw_y,(double)raw_x)* 180 / 3.14159265 + 180;
	return headingDegrees;
}

// Pressure Sensor
void SENSOR_MS5611_init(void)
{
// to complete code	
}

int8_t SENSOR_MS5611_getPressure(void)
{
	// to complete code
	return 1;
}

// 3-Tilt Axis
void SENSOR_xxxx_init(void)
{
	// to complete code
}

int8_t SENSOR_xxxx_getAxis(void)
{
	// to complete code
	return 1;
}

// GPS module
void SENSOR_GPS_init(void)
{
	#define PMTK_SET_NMEA_OUTPUT_GPPAONLY "$PMTK314,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29"
	USART_transmit_string(PMTK_SET_NMEA_OUTPUT_GPPAONLY);
}

int8_t SENSOR_GPS_getLocation(void)
{
	// to complete code
	return 1;
}

uint8_t SENSOR_GPS_locationCheck(uint8_t)
{
	return 1;
}