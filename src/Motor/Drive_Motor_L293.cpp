/**
 * L293D DC-Motor for Drive library.
 *
 * @author Roland Rusch <roland@rusch.lu>
 */

#include "Drive_Motor_L293.h"

Drive_Motor_L293::Drive_Motor_L293(uint8_t pinEn, uint8_t pin1A, uint8_t pin2A)
{
	this->pinEn=pinEn;
	this->pin1A=pin1A;
	this->pin2A=pin2A;
	
	this->direction=Drive::DIR_UNDEF;
	this->speed=0;
	this->stopped=true;
	
	pinMode(this->pinEn, OUTPUT);
	digitalWrite(this->pinEn, LOW);
	pinMode(this->pin1A, OUTPUT);
	digitalWrite(this->pin1A, LOW);
	pinMode(this->pin2A, OUTPUT);
	digitalWrite(this->pin2A, LOW);
}



void Drive_Motor_L293::stopEngine()
{
	if(!this->isRunning()) return;
	this->stop();
	digitalWrite(this->pinEn, LOW);
}


void Drive_Motor_L293::startEngine()
{
	if(this->isRunning()) return;
	this->stop();
}


void Drive_Motor_L293::setSpeedPercent(int percent)
{
	if(percent > 100) percent=100;
	if(percent < 0) percent=0;
	this->speed=(percent * 255) / 100;
	if( !this->isStopped() ) this->drive();
}


void Drive_Motor_L293::setDirection(int direction)
{
	this->direction=direction;
}


void Drive_Motor_L293::stop()
{
	if(!this->isReady()) return;
	digitalWrite(this->pinEn, HIGH);
	digitalWrite(this->pin1A, LOW);
	digitalWrite(this->pin2A, LOW);
	this->stopped=true;
}


void Drive_Motor_L293::drive()
{
	if(!this->isReady()) return;
	this->stopped=false;

	if(this->direction == Drive::DIR_FORWARD)
	{
		digitalWrite(this->pin1A, HIGH);
		digitalWrite(this->pin2A, LOW);
		analogWrite(this->pinEn, this->speed);
	}

	if(this->direction == Drive::DIR_BACKWARD)
	{
		digitalWrite(this->pin1A, LOW);
		digitalWrite(this->pin2A, HIGH);
		analogWrite(this->pinEn, this->speed);
	}
}


bool Drive_Motor_L293::isRunning()
{
	return this->isReady();
}


bool Drive_Motor_L293::isReady()
{
	return true;
}


bool Drive_Motor_L293::isStopped()
{
	return !this->isReady() || this->stopped;
}

