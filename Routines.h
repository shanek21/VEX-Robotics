#include "AutoControls.h"

#define MIDLOW 900
#define MID 1200
#define FULLTURN 46
#define QUARTERTURN 14

void backRight2Launch()
{
	//Deploy rollers
	buckyIntake(-127);
	driveForwardInches(3);
	buckyIntake(127);
	driveBackwardInches(2);

	//Drive Forwards to bick up large balls
	driveForwardInches(26);
	driveBackwardInches(2);
	wait10Msec(50);
	buckyIntake(0);
	turnRightInches(29);
	wait10Msec(25);
	launchFull();
	turnRightInches(14);
	buckyIntake(127);
	driveForwardInches(23):
	wait10Msec(40);
	driveBackwardInches(21);
	wait10Msec(50);
	buckyIntake(0):
	turnLeftInches(15);
	wait10Msec(25);
	launchFull();
	turnLeftInches(8);
	buckyIntake(127);

	//Knock bump balls and drive back
	driveForwardInches(28);
}

void backRight3Ball()
{
	//Deploy rollers
	buckyIntake(-127);
	driveForwardInches(5);
	buckyIntake(127);
	driveBackwardInches(5);

	//Drive Forwards to bick up large balls
	driveForwardInches(30);
	wait10Msec(40);
	buckyIntake(0);
	turnRightInches(29);
	wait10Msec(30);
	launchFull();
	turnLeftInches(9);
	buckyIntake(127);
	drive(127);
	wait10Msec(120);
	drive(0);
	wait10Msec(230);
	driveForwardInches(15);
	wait10Msec(20);


	turnRightInches(11);
	driveForwardInches(50);
	turnLeftInches(12);
	driveBackwardInches(60);
}

void frontRightStandard()
{
	StartTask(pidLiftHoldPosition);
  pidLiftOn = false;
	SensorValue(hang) = 1;

	//Deploy rollers
	buckyIntake(127);
	driveForwardInches(3);
	driveBackwardInches(2);

	//Stash
	driveForwardInches(48);
	pidLiftOn = true;
	StartTask(liftHigh);
	wait10Msec(100);
	drive(80);
	wait10Msec(80);
	drive(0);
	buckyIntake(-127);
	wait10Msec(100);
	drive(-80);
	wait10Msec(30);
	liftTime(80, -127);
	drive(0);
	pidLiftOn = 0;
	driveBackwardInches(46);
	buckyIntake(0);
	SensorValue(catapultAll) = true;
	driveForwardInches(26);
	driveBackwardInches(26);
	SensorValue(catapultAll) = false;
	pidLiftOn = true;
	StartTask(liftMid);
	turnLeftInches(6);
	driveForwardInches(28);
}

void backRightStash()
{
	StartTask(pidLiftHoldPosition);
  pidLiftOn = false;
  SensorValue(hang) = 1;
	//Deploy rollers
	buckyIntake(127);
	driveForwardInches(3);
	driveBackwardInches(2);

	//Pick Up Buckies
	driveForwardInches(13);
	wait10Msec(50);
	driveBackwardInches(53);
	turnRightInches(21);
	drive(-50);
	wait10Msec(55);
	driveForwardInches(5);
	turnLeftInches(3);
	driveForwardInches(48);
	pidLiftOn = true;
	StartTask(liftHigh);
	wait10Msec(100);
	drive(80);
	wait10Msec(140);
	drive(0);
	buckyIntake(-127);
	wait10Msec(300);
	drive(-60);
	wait10Msec(40);
	liftTime(80, -127);
	drive(0);
	pidLiftOn = 0;
}

void frontRightDefense()
{
		StartTask(pidLiftHoldPosition);
  pidLiftOn = false;
	SensorValue(hang) = 1;

	//Deploy rollers
	buckyIntake(127);
	driveForwardInches(5);
	driveBackwardInches(4);

	//Stash
	driveForwardInches(48);
	pidLiftOn = true;
	StartTask(liftHigh);
	wait10Msec(100);
	drive(80);
	wait10Msec(80);
	drive(0);
	buckyIntake(-127);
	wait10Msec(100);
	drive(-80);
	wait10Msec(40);
	turnRightInches(11);
	drive(-127);
	liftTime(120, -127);
	driveBackwardInches(30);
	drive(0);
}

/////////////////////////////////////////
/////////////////////////////////////////
//LEFT SIDE//////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////

//done
void backLeft2Launch()
{
	//Deploy rollers
	buckyIntake(-127);
	driveForwardInches(3);
	buckyIntake(127);
	driveBackwardInches(2);

	//Drive Forwards to bick up large balls
	driveForwardInches(28);
	driveBackwardInches(2);
	wait10Msec(50);
	buckyIntake(0);
	turnLeftInches(33);
	wait10Msec(25);
	launchFull();
	turnLeftInches(16);
	buckyIntake(127);
	driveForwardInches(26):
	wait10Msec(40);
	driveBackwardInches(29);
	wait10Msec(50);
	buckyIntake(0):
	turnRightInches(14);
	wait10Msec(25);
	launchFull();
	turnRightInches(8);
	buckyIntake(127);

	//Knock bump balls and drive back
	driveForwardInches(28);
}

//done
void backLeft3Ball()
{
	//Deploy rollers
	buckyIntake(-127);
	driveForwardInches(5);
	buckyIntake(127);
	driveBackwardInches(3);

	//Drive Forwards to bick up large balls
	driveForwardInches(30);
	wait10Msec(40);
	buckyIntake(0);
	turnLeftInches(34);
	wait10Msec(30);
	launchFull();
	turnRightInches(6);
	buckyIntake(127);
	drive(127);
	wait10Msec(120);
	drive(0);
	wait10Msec(230);
	driveForwardInches(15);
	wait10Msec(20);


	turnLeftInches(15);
	driveForwardInches(50);
	turnRightInches(11);
	driveBackwardInches(60);
}

//done
void frontLeftStandard()
{
	StartTask(pidLiftHoldPosition);
  pidLiftOn = false;
	SensorValue(hang) = 1;

	//Deploy rollers
	buckyIntake(127);
	driveForwardInches(3);
	driveBackwardInches(2);

	//Stash
	driveForwardInches(48);
	pidLiftOn = true;
	StartTask(liftHigh);
	wait10Msec(100);
	drive(80);
	wait10Msec(80);
	drive(0);
	buckyIntake(-127);
	wait10Msec(65);
	drive(-80);
	wait10Msec(30);
	liftTime(80, -127);
	drive(0);
	pidLiftOn = 0;
	driveBackwardInches(46);
	buckyIntake(0);
	SensorValue(catapultAll) = true;
	driveForwardInches(26);
	driveBackwardInches(26);
	SensorValue(catapultAll) = false;
	pidLiftOn = true;
	StartTask(liftMid);
	turnRightInches(6);
	driveForwardInches(28);
}

//done
void backLeftStash()
{
	StartTask(pidLiftHoldPosition);
  pidLiftOn = false;
  SensorValue(hang) = 1;
	//Deploy rollers
	buckyIntake(127);
	driveForwardInches(3);
	driveBackwardInches(2);

	//Pick Up Buckies
	driveForwardInches(12);
	wait10Msec(50);
	driveBackwardInches(53);
	turnLeftInches(23);
	drive(-50);
	wait10Msec(50);
	driveForwardInches(21);
	turnRightInches(3);
	driveForwardInches(33);
	pidLiftOn = true;
	StartTask(liftHigh);
	wait10Msec(100);
	drive(80);
	wait10Msec(140);
	drive(0);
	buckyIntake(-127);
	wait10Msec(300);
	drive(-60);
	wait10Msec(40);
	liftTime(80, -127);
	drive(0);
	pidLiftOn = 0;
}

//done
void frontLeftDefense()
{
	StartTask(pidLiftHoldPosition);
  pidLiftOn = false;
	SensorValue(hang) = 1;

	//Deploy rollers
	buckyIntake(127);
	driveForwardInches(5);
	driveBackwardInches(4);

	//Stash
	driveForwardInches(48);
	pidLiftOn = true;
	StartTask(liftHigh);
	wait10Msec(100);
	drive(80);
	wait10Msec(80);
	drive(0);
	buckyIntake(-127);
	wait10Msec(100);
	drive(-80);
	wait10Msec(40);
	turnLeftInches(16);
	drive(-127);
	liftTime(120, -127);
	driveBackwardInches(30);
	drive(0);
}
