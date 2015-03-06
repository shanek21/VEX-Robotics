//Autonomous commands

#include "SensorProcessing.h"
#include "MotorControl.h"
#define TOLERANCE 20
#define KPDRIVE 2
#define HIGH_LIFT 2100
#define TICKSPERINCH 31

static bool liftTask = false;

//Limits the maximum motor value
int limit(int value)
{
  if (value > 127)
    return 127;
  else if (value < -127)
    return -127;
  else
    return value;
}

//Limits maximum motor value and creates a minimum value
int joyStickLimit(int value)
{
	 if (value > 127)
    return 127;
  else if (value < -127)
    return -127;
  else if (value < 25 && value > -25)
  	return 0;
  else
    return value;
}

//Lifts at power for certain amount of time
void liftTime(int time, int power = 127)
{
	pidLiftOn = false;
	motor[liftLeft1] = power;
	motor[liftLeft2] = power;
	motor[liftRight1] = power;
	motor[liftRight2] = power;
	wait10Msec(time);
	motor[liftLeft1] = 0;
	motor[liftLeft2] = 0;
	motor[liftRight1] = 0;
	motor[liftRight2] = 0;
	liftRequestedValue = (SensorValue(rightPot));
	pidLiftOn = true;
}

//Lifts at power to position
void liftPosition(int position, int power = 127)
{
	pidLiftOn = false;
	if (liftHeight() < position)
	{
		lift(power);
		while (liftHeight() < position);
		lift(0);
		liftRequestedValue = liftHeight();
	}

	else if (liftHeight() > position)
	{
		lift(power);
		while (liftHeight() > position);
		lift(0);
		liftRequestedValue = liftHeight();
	}
	pidLiftOn = true;
}

//Drives forwards a distance on a p-controller
void driveForwardDistance(int distance, int power)
{
	int error;
	int targetCount = 0;
	nMotorEncoder[driveLeft1] = 0;
	nMotorEncoder[driveRight1] = 0;

	while(1)
	{
		error = (distance - encoderDistance());
		if (error <= TOLERANCE && error >= -TOLERANCE)
		{
			targetCount++;
			if (targetCount >= 2000)
			{
				drive(0);
				break;
			}
		}

		else
			targetCount = 0;

		drive((error * KPDRIVE));
	}
}

//Drives backwards distance on a p-controller
void driveBackwardDistance(int distance, int power)
{
	int error;
	int targetCount = 0;
	nMotorEncoder[driveLeft1] = 0;
	nMotorEncoder[driveRight1] = 0;

	while(1)
	{
		error = (distance - encoderDistance());
		if (error <= TOLERANCE && error >= -TOLERANCE)
		{
			targetCount++;
			if (targetCount >= 2000)
			{
				drive(0);
				break;
			}
			else
			{
				drive(0);
				continue;
			}
		}

		else
			targetCount = 0;

		drive(-(error * KPDRIVE));
	}
}

//TUrns right distance on a p-controller
void turnRightDistance(int distance, int power)
{
	int error;
	int targetCount = 0;
	nMotorEncoder[driveLeft1] = 0;
	nMotorEncoder[driveRight1] = 0;

	while(1)
	{
		error = (distance - encoderTurnDistance());
		if (error <= TOLERANCE && error >= -TOLERANCE)
		{
			targetCount++;
			if (targetCount >= 2000)
			{
				drive(0);
				break;
			}
			else
			{
				drive(0);
				continue;
			}
		}

		else
			targetCount = 0;

		turn(error * KPDRIVE);
	}
}

//Turns left distance on a p-controller
void turnLeftDistance(int distance, int power)
{
	int error;
	int targetCount = 0;
	nMotorEncoder[driveLeft1] = 0;
	nMotorEncoder[driveRight1] = 0;

	while(1)
	{
		error = -(distance - encoderTurnDistance());
		if (error <= TOLERANCE && error >= -TOLERANCE)
		{
			targetCount++;
			if (targetCount >= 2000)
			{
				drive(0);
				break;
			}
			else
			{
				drive(0);
				continue;
			}
		}

		else
			targetCount = 0;

		turn(error * KPDRIVE);
	}
}

//Lifts to scoring position
task liftHigh()
{
	pidLiftOn = false;
	liftTask = true;
	while (SensorValue(rightPot) < 2000)
	{
		lift(127);
		if(vexRT(Btn6U) == 1 ||  vexRT(Btn6D) == 1)
		{
			liftTask = false;
			StopTask(liftHigh);
		}
	}
	lift(0);
	liftTask = false;
	liftRequestedValue = 2400;
	pidLiftOn = true;
	StopTask(liftHigh);
}

task liftMid()
{
	pidLiftOn = false;
	while (SensorValue(rightPot) < 1500)
	{
		lift(127);
		if(vexRT(Btn6U) == 1 ||  vexRT(Btn6D) == 1)
			StopTask(liftHigh);
	}
	lift(0);
	liftRequestedValue = 1500;
	pidLiftOn = true;
	StopTask(liftHigh);
}

//Full laucnh sequence
void launchFull()
{
	SensorValue(catapultAll) = true;
	SensorValue(catapultHalf) = true;
	wait10Msec(50);
	SensorValue(catapultAll) = false;
	SensorValue(catapultHalf) = false;
}

//Half shot launch sequence
void launchHalf()
{
	SensorValue(catapultAll) = true;
	wait10Msec(50);
	SensorValue(catapultAll) = false;
}

//Drive functions using inch distances
void driveForwardInches(int inches)
{
	driveForwardDistance((inches * TICKSPERINCH), 127);
}

void driveBackwardInches(int inches)
{
	driveBackwardDistance((inches * TICKSPERINCH), 127);
}

void turnRightInches(int inches)
{
	turnRightDistance((inches * TICKSPERINCH), 127);
}

void turnLeftInches(int inches)
{
	turnLeftDistance((inches * TICKSPERINCH), 127);
}

//Bucky Pick Up Sequence
void buckyStrafeRight(int distance)
{
	int error;
	int targetCount = 0;
	nMotorEncoder[driveLeft1] = 0;
	nMotorEncoder[driveRight1] = 0;

	while(encoderTurnDistance() < distance)
	{
		error = -(distance - encoderTurnDistance());
		if (error <= TOLERANCE && error >= -TOLERANCE)
		{
			targetCount++;
			if (targetCount >= 2000)
			{
				drive(0);
				break;
			}
			else
			{
				drive(0);
				continue;
			}
		}

		else
			targetCount = 0;

		motor[driveLeft1] = 75;
		motor[driveLeft2] = 75;
		motor[driveRight1] = 90;
		motor[driveRight2] = 90;
	}
	drive(0):
}
