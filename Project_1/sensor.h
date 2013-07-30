/*
 * sensor.h
 *
 * Created: 10/07/2013 5:31:49 p.m.
 *  Author: Liam
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

void SENSOR_HMC5883L_init(void);
float SENSOR_HMC5883L_getHeading(void);

void SENSOR_MS5611_init(void);
int8_t SENSOR_MS5611_getPressure(void);

void SENSOR_xxxx_init(void);
int8_t SENSOR_xxxx_getAxis(void);

void SENSOR_GPS_init(void);
uint8_t SENSOR_GPS_getLocation(void);
uint8_t SENSOR_GPS_locationCheck(uint8_t);

#endif /* SENSOR_H_ */