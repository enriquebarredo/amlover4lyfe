/*
 * Seguidor_Linea_prototipo.c
 *
 * Created: 26/03/2019 13:45:19
 * Author : Enrique
 */ 

	#include <avr/io.h>
	#include "Motors.h"

	int main(void)
	{
	int Sensor_LEFT;					//SENSORES
	int Sensor_RIGHT;
	Sensor_LEFT =0;
	Sensor_RIGHT=0;
	
	DDRB &=(~(1<<DDB3))&(~(1<<DDB4));

	Motors_init();
	

	while(1)
		{
			Sensor_LEFT =PINB&0b00001000; //Read PB3, 4th from LSB. 8
			Sensor_RIGHT=PINB&0b00010000; //Read PB4, 5th from LSB. 16
	
			if((Sensor_LEFT==0x00) & (Sensor_RIGHT==0x00)) //Both dark, horizontal line
				{
					Motor_RIGHT(MOTOR_FORWARD,120);		//Go Forth!
					Motor_LEFT(MOTOR_FORWARD,120);
				}
				
			if((Sensor_LEFT==0x08) & (Sensor_RIGHT==0x10)) //Both bright, following line
				{
					Motor_RIGHT(MOTOR_FORWARD,120); //Go Forth!
					Motor_LEFT(MOTOR_FORWARD,120);
				}
			if((Sensor_LEFT==0x00) & (Sensor_RIGHT==0x10))
				{
					Motor_RIGHT(MOTOR_BACKWARD,120); //Right turn!
					Motor_LEFT(MOTOR_FORWARD,120);
				}
			if((Sensor_LEFT==0x08) & (Sensor_RIGHT==0x00))
				{
					Motor_RIGHT(MOTOR_FORWARD,120); //Left turn!
					Motor_LEFT(MOTOR_BACKWARD,120);
				}
		}
	}