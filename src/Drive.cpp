/**
 * Drive library.
 *
 * @author Roland Rusch <roland@rusch.lu>
 */

#include "Drive.h"


Drive::Drive(Drive_Motor *motor /*=NULL*/)
{
	this->_motor=motor;
};


void Drive::setup(Drive_Motor *motor /*=NULL*/)
{
	if(motor != NULL) this->_motor=motor;
	this->_motor->setup();
};


bool Drive::isMotorReady()
{
	return (this->_motor != NULL) && this->_motor->isReady();
}


bool Drive::isStopped()
{
	return !this->isMotorReady() || this->_motor->isStopped();
}


void Drive::update()
{
};


void Drive::startEngine()
{
	if(this->isMotorReady()) this->_motor->startEngine();
};


void Drive::stopEngine()
{
	if(this->isMotorReady()) this->_motor->stopEngine();
};


void Drive::setSpeedPercent(int percent)
{
	if(this->isMotorReady()) this->_motor->setSpeedPercent(percent);
};


void Drive::setDirection(int direction)
{
	if(this->isMotorReady()) this->_motor->setDirection(direction);
};


void Drive::stop()
{
	if(this->isMotorReady()) this->_motor->stop();
};


void Drive::drive()
{
	if(this->isMotorReady()) this->_motor->drive();
};

