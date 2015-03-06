//Functions act as intermediaries between sensor value readouts and sensor usage

//Potentiometer value on lift
int liftHeight()
{
	return ((SensorValue(rightPot)));
}

//Average drive encoder distance
int encoderDistance()
{
	return ((abs(nMotorEncoder[driveLeft1])));
}

//Average Encoder DIstance for Use in Turning
int encoderTurnDistance()
{
	return (abs(nMotorEncoder[driveLeft1]));
}

//Left Drive Encoder Distance
int leftEncoderDistance()
{
	return -nMotorEncoder[driveLeft1];
}

//RIght Drive Encoder Distance
int rightEncoderDistance()
{
	return nMotorEncoder[driveLeft1];
}

//Potentiometer Values for autonomous selection
int autoSelector()
{
	if	(SensorValue(leftPot) >= 32 && SensorValue(leftPot) < 934)
		return 1;
	else if	(SensorValue(leftPot) >= 934 && SensorValue(leftPot) < 1587)
		return 2;
	else if	(SensorValue(leftPot) >= 1587 && SensorValue(leftPot) < 2204)
		return 3;
	else if	(SensorValue(leftPot) >= 2204 && SensorValue(leftPot) < 2970)
		return 4;
	else if	(SensorValue(leftPot) >= 2970 && SensorValue(leftPot) < 4095)
		return 5;
	else
		return 0;
}

bool buttonPressed()
{
	if (SensorValue(leftSwitch) == 1)
		return true;
	else if (SensorValue(rightSwitch) == 1)
		return true;
	else if (SensorValue(frontSwitch) == 1)
		return true;
	else
		return false;
}

bool rightButton()
{
	return (SensorValue(rightSwitch));
}

bool leftButton()
{
	return (SensorValue(leftSwitch));
}
