//Functions act as intermediaries between robot functions and motor commands

#include "PIDControl.h"

//Drive motors set to value power
void drive(int power)
{
	motor[driveRight1] = power;
	motor[driveRight2] = power;
	motor[driveLeft1] = power;
	motor[driveLeft2] = power;
}

//Drive motors set to value power to turn
void turn(int power)
{
	motor[driveRight1] = -power;
	motor[driveRight2] = -power;
	motor[driveLeft1] = power;
	motor[driveLeft2] = power;
}

//Sets lift motors to power
void lift(int power)
{
	motor[liftLeft1] = power;
	motor[liftLeft2] = power;
	motor[liftRight1] = power;
	motor[liftRight2] = power;
}

//Sets bucky ball inatke to power
void buckyIntake(int power)
{
	motor[intake] = power;
}

//Sets large ball intake to power
void largeIntake(int power)
{
}
