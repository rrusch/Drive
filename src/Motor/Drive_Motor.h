/**
 * Motor interface for Drive library.
 *
 * @author Roland Rusch <roland@rusch.lu>
 */

#ifndef RRUSCH_DRIVE_MOTOR_H
#define RRUSCH_DRIVE_MOTOR_H

#include <Arduino.h>


class Drive_Motor
{

public:
	virtual void setup(){};

	virtual void startEngine(){};
	virtual void stopEngine(){};

	virtual void setSpeedPercent(int percent){};
	virtual void setDirection(int direction){};

	virtual void stop(){};
	virtual void drive(){};

	virtual bool isReady(){ return false; };
	virtual bool isRunning(){ return false; };
	virtual bool isStopped(){ return true; };

	virtual ~Drive_Motor(){};

private:


};




#endif /* RRUSCH_DRIVE_MOTOR_H */
