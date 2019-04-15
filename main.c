#pragma config(Sensor, in7,    sonar,          sensorAnalog)
#pragma config(Sensor, in8,    encoder,        sensorAnalog)
#pragma config(Sensor, dgtl12, LED,            sensorLEDtoVCC)
#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           gate,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           claw,          tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int direction = 1;

void moveWheels()
{
	if(direction==1) {
		motor[rightMotor] = vexRT[Ch2];
		motor[leftMotor] = vexRT[Ch3];
	}
	else {
		motor[rightMotor] = vexRT[Ch3]*-1;
		motor[leftMotor] = vexRT[Ch2]*-1;
	}
}

bool gateOpen = true;
bool Btn6DPressed = false;

void manageGate()
{
	if(vexRT[Btn6D] == 1 && !Btn6DPressed) {
		if(gateOpen) {
			setServo(gate,127);
			waitInMilliseconds(100);
			gateOpen = false;
		}
		else {
			setServo(gate,-127);
			waitInMilliseconds(100);
			gateOpen = true;
		}
		Btn6DPressed = true;
	}
	if(vexRT[Btn6D] == 0) {
		Btn6DPressed = false;
	}
}

bool Btn7LPressed = false;

void reverseDirection()
{
	if(vexRT[Btn7L] == 1 && !Btn7LPressed) {
		if(direction==1)
			direction = -1;
		else
			direction = 1;
		Btn7LPressed = true;
	}
	if(vexRT[Btn7L] == 0)
		Btn7LPressed = false;
}

task main()
{
	while(true) {
		moveWheels();
		manageGate();
		reverseDirection();

	}
}
