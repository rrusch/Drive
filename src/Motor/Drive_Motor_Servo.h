/**
 * Hacked Servo Motor for Drive library.
 *
 * @author Roland Rusch <roland@rusch.lu>
 */

#ifndef RRUSCH_DRIVE_MOTOR_SERVO_H
#define RRUSCH_DRIVE_MOTOR_SERVO_H

#include <Arduino.h>
#include <Servo.h>
#include "../Drive.h"
#include "Drive_Motor.h"

class Drive_Motor_Servo: public Drive_Motor
{

public:
	Drive_Motor_Servo(int pin=NOT_A_PIN);
	void setPin(int pin);

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
	int _pin;
	Servo *_servo;
	int _motorOffset;
	int _servoValue;
	int _direction;
	bool _stopped;

};



#endif /* RRUSCH_DRIVE_MOTOR_SERVO_H */
