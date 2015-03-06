#define LEFT_LIFT_SENSOR leftPot
#define RIGHT_LIFT_SENSOR rightPot
#define LIFT_I_LIMIT 50

#define MASTER_DRIVE_SENSOR driveRight1
#define SLAVE_DRIVE_SENSOR driveLeft1
#define DRIVE_I_LIMIT 50

static bool pidLiftOn;
static float liftRequestedValue;
static float liftKp = .15;
static float liftKi = .01;
static float liftKd = .3;

static bool pidDriveOn;
static float driveKp = 0;
static float driveKi = 0;
static float driveKd = 0;

int limit(int value)
{
  if (value > 127)
    return 127;
  else if (value < -127)
    return -127;
  else
    return value;
}

//Compare average sensor value (two sensors) to target value and return converted error to hold target.
task pidLiftHoldPosition()
{
	float error = 0;
	float lastError = 0;
	float integral = 0;
	float derivative = 0;
	float drive = 0;
	float liftCurrentValue;
	while(1)
	{
		if(pidLiftOn)
		{
			//Take average of current height value for reference
			liftCurrentValue = SensorValue(rightPot);

			//Calculate Error (Result sign corresponds with necessary motor direction)
			error = liftCurrentValue - liftRequestedValue;

			//Calculate integral
			if(liftKi != 0)
			{
				//Check if integral is within controllable range
				if(abs(error) < LIFT_I_LIMIT)
					integral += error;
				else
					integral = 0;
			}
			else
				integral = 0;

			//Calculate derivative
			derivative = error - lastError;
			lastError = error;

			//Calculate lift motor drive value
			drive = limit((liftKp * error) + (liftKi * integral) + (liftKd * derivative));

			//Assign lift motors the drive value
			motor[liftLeft1] = -drive;
			motor[liftLeft2] = -drive;
			motor[liftRight1] = -drive;
			motor[liftRight2] = -drive;
		}
		else
		{
			//Clear PID control values
			error = 0;
			lastError = 0;
			integral = 0;
			derivative = 0;
		}

		//Run at 50Hz
		wait1Msec(25);
	}
}

task pidDriveSpeedControl()
{
	float error = 0;
	float lastError = 0;
	float integral = 0;
	float derivative = 0;
	float drive = 0;
	int lastMaster = 0;
	int lastSlave = 0;
	while(1)
	{
		if(pidDriveOn)
		{
			//Calculate Error (Result sign corresponds with necessary motor direction)
			error = ((abs(nMotorEncoder(MASTER_DRIVE_SENSOR)) - lastMaster)) - ((abs(nMotorEncoder(SLAVE_DRIVE_SENSOR)) - lastSlave));
			lastMaster = abs(nMotorEncoder(MASTER_DRIVE_SENSOR));
			lastSlave = abs(nMotorEncoder(SLAVE_DRIVE_SENSOR));

			//Calculate integral
			if(driveKi != 0)
			{
				//Check if integral is within controllable range
				if(abs(error) < DRIVE_I_LIMIT)
					integral += error;
				else
					integral = 0;
			}
			else
				integral = 0;

			//Calculate derivative
			derivative = error - lastError;
			lastError = error;

			//Calculate drive motor additive drive value
			drive = limit((driveKp * error) + (driveKi * integral) + (driveKd * derivative));

			//Add drive value to the motors
			motor[driveLeft1] = limit(motor[driveLeft1] + drive);
			motor[driveLeft2] = limit(motor[driveLeft2] + drive);
			//motor[driveLeft3] = limit(motor[driveLeft3] + drive);
		}
		else
		{
			//Clear PID control values
			error = 0;
			lastError = 0;
			integral = 0;
			derivative = 0;
		}

		//Run at 50Hz
		wait1Msec(25);
	}
}
