/**
 * L293D DC-Motor for Drive library.
 *
 * @author Roland Rusch <roland@rusch.lu>
 */

#ifndef RRUSCH_DRIVE_MOTOR_L293_H
#define RRUSCH_DRIVE_MOTOR_L293_H

#include <Arduino.h>
#include "../Drive.h"

class Drive_Motor_L293: public Drive_Motor
{

public:
	Drive_Motor_L293(uint8_t pinEn, uint8_t pin1A, uint8_t pin2A);
	
	void startEngine();
	void stopEngine();
	
	void setSpeedPercent(int percent);
	void setDirection(int direction);
	
	void stop();
	void drive();
	
	bool isReady();
	bool isRunning();
	bool isStopped();


private:
	uint8_t pinEn;
	uint8_t pin1A;
	uint8_t pin2A;
	
	int direction;
	int speed;
	bool stopped;
	
};



#endif /* RRUSCH_DRIVE_MOTOR_L293_H */
