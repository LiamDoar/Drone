/*
 * nmea.cpp
 *
 * Created: 16/07/2013 11:10:42 a.m.
 *  Author: Liam
 */ 

#define NMEA_test "$GPGGA,123519.000,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47" // for testing
#include <avr/io.h>

void NMEA_getUTC (void)
{
	char NMEA_messagetest[80] = "$GPGGA,123519.000,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
	int UTC = 0;
	uint8_t i = 8;
	// get UTC time [hhmmss.sss]
	while(NMEA_messagetest[i] != ',');
	{
		UTC = (NMEA_messagetest[i]);
		i++;
	
	}
	

}

void NMEA_getValid (void)
{
	
}

void NMEA_getlatitude (void)
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