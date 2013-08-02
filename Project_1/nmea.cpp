/*
 * nmea.cpp
 *
 * Created: 16/07/2013 11:10:42 a.m.
 *  Author: Liam
 */ 

#define NMEA_test "$GPGGA,123519.000,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47" // for testing
#define GPGGA_TIME_POISTION 1
#define GPGGA_LAT_POISTION 2

#include <avr/io.h>
#include <stdlib.h>

float NMEA_getUTC (char NMEA_Text[])
{
	uint8_t count = 0;
	uint8_t n = 0;
	uint8_t i = 0;
	char pBuff[10];
	
	while (!(count == GPGGA_TIME_POISTION))
	{
		if (NMEA_Text[n] == ',')
		{
			count++;
		}
		
		n++;
	}
	
	while (!(NMEA_Text[(n+i)] == ','))
	{
		pBuff[i] = NMEA_Text[n+i];
		i=i++;
	}
	pBuff[i] = '\0';
	
	return (atof(pBuff));
}

float NMEA_getLatitude (char NMEA_Text[])
{
	//4807.038,N
	uint8_t count = 0;
	uint8_t n = 0;
	uint8_t i = 0;
	uint8_t degress = 0;
	float minutes = 0.0;
	float latatude = 0.0;
	char pBuff[10];
	while (!(count == GPGGA_LAT_POISTION))
	{
		if (NMEA_Text[n] == ',')
		{
			count++;
		}
		
		n++;
	}
	
	while (!(i==2))
	{
		pBuff[i] = NMEA_Text[n+i];
		i=i++;
	}
	pBuff[i] = '\0';
	degress = atoi(pBuff);
	
	while (!(NMEA_Text[(n+i)]==','))
	{
		pBuff[i-2] = NMEA_Text[n+i];
		i=i++;
	}
	pBuff[i-2] = '\0';
	minutes = atof(pBuff);
	
	latatude = (degress + (minutes/60));
	
	if (NMEA_Text[n+i+1] = 'S')
	{
		latatude = latatude * -1;
	}
	
	return latatude;
}
	



void NMEA_getValid (void)
{
	
}


void NMEA_getNS (void)
{
	
}
void NMEA_getLongitude (void)
{
	
}
void NMEA_getEW (void)
{
	
}
void NMEA_getChecksum (void)
{
	
}

/*
 $GPGGA,123519.000,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47

 Where:
 GGA          Global Positioning System Fix Data
 123519       Fix taken at 12:35:19 UTC
 4807.038,N   Latitude 48 deg 07.038' N
 01131.000,E  Longitude 11 deg 31.000' E
 1            Fix quality: 0 = invalid
 1 = GPS fix (SPS)
 2 = DGPS fix
 3 = PPS fix
 4 = Real Time Kinematic
 5 = Float RTK
 6 = estimated (dead reckoning) (2.3 feature)
 7 = Manual input mode
 8 = Simulation mode
 08           Number of satellites being tracked
 0.9          Horizontal dilution of position
 545.4,M      Altitude, Meters, above mean sea level
 46.9,M       Height of geoid (mean sea level) above WGS84
 ellipsoid
 (empty field) time in seconds since last DGPS update
 (empty field) DGPS station ID number
 *47          the checksum data, always begins with *
*/

/*
 volatile uint8_t time[10];
 volatile uint8_t valid[1];
 volatile uint8_t latitude[9];
 volatile uint8_t ns[1];
 volatile uint8_t longitude[10];
 volatile uint8_t ew[1];
 volatile uint8_t speed[6];
 volatile uint8_t course[6];
 volatile uint8_t date[6];
 */