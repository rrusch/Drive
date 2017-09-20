/**
 * Drive library.
 *
 * @author Roland Rusch <roland@rusch.lu>
 * @version 0.0.1
 */


#ifndef RRUSCH_DRIVE_H
#define RRUSCH_DRIVE_H

#include <Arduino.h>
#include "Motor/Drive_Motor.h"
#include "Motor/Drive_Motor_Servo.h"
#include "Motor/Drive_Motor_L293.h"

class Drive
{

public:
	Drive(Drive_Motor *motor=NULL);
	void setup(Drive_Motor *motor=NULL);
	void update();
	
	bool isMotorReady();
	bool isStopped();
	
	void startEngine();
	void stopEngine();
	
	void setSpeedPercent(int percent);
	void setDirection(int direction);
	const static int DIR_UNDEF=0;
	const static int DIR_FORWARD=1;
	const static int DIR_BACKWARD=2;
	
	void stop();
	void drive();
	
	
	const static int MOTORTYPE_NONE=0;
	const static int MOTORTYPE_SERVO=0;
	
private:
	Drive_Motor *_motor;

};



#endif /* RRUSCH_DRIVE_H */
