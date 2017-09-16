/**
 * This is the test program for the Drive library.
 *
 * @author Roland Rusch <roland@rusch.lu>
 */


#include "Arduino.h"
#include "libraries/Led/Led.h"
#include "libraries/Button/Button.h"
#include "../../src/Drive.h"



// Initialize the Led objects
Led led(LED_BUILTIN);
Led greenLed(7);
Led blueLed(9);


// Button pin
Button b1(4);
Button b2(5);

// Potentiometer pin
const int pinP1 = A0;

// Motor pin
const int motorServoPin = 8;
Drive_Motor_Servo motorServo(motorServoPin);
Drive drive(&motorServo);

int speed=0;


void b1Pressed(Button &button)
{
	if(drive.isStopped())
	{
		greenLed.setOn();
		drive.setDirection(Drive::DIR_FORWARD);
		drive.startEngine();
		drive.drive();
	} else
	{
		greenLed.setOff();
		blueLed.setOff();
		drive.stop();
	}
}


void b1Released(Button &button)
{
}

void b2Pressed(Button &button)
{
	if(drive.isStopped())
	{
		blueLed.setOn();
		drive.setDirection(Drive::DIR_BACKWARD);
		drive.drive();
	} else
	{
		greenLed.setOff();
		blueLed.setOff();
		drive.stop();
	}
}


void b2Released(Button &button)
{
}


//The setup function is called once at startup of the sketch
void setup()
{
	// Run the setup routine of the Led object
	led.setup();
	greenLed.setup();
	
	
	// Button 1 setup
	b1.setup();
	b1.onKeyPressed(b1Pressed);
	b1.onKeyReleased(b1Released);
	
	// Button 2 setup
	b2.setup();
	b2.onKeyPressed(b2Pressed);
	b2.onKeyReleased(b2Released);
	
	// Drive setup
	drive.setup();
	drive.startEngine();
}



// The loop function is called in an endless loop
void loop()
{
	// Run the update routine of the Led object
	led.update();
	greenLed.update();
	b1.update();
	b2.update();
	drive.update();
	
	speed=analogRead(pinP1) / 10;
	drive.setSpeedPercent(speed);
	led.setBlinker( (100 - speed) * 5 + 20 );
	
}
