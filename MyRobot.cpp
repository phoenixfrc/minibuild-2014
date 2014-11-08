#include "WPILib.h"
#include "PortAssignments.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{
	RobotDrive driveTrain; // both drive wheels/motors
	Joystick leftStick;
	Joystick rightStick;
	Talon roller;

public:
	RobotDemo():
		driveTrain(PortAssign::leftMotorChannel, PortAssign::rightMotorChannel), // these must be initialized in the same order
		leftStick(PortAssign::leftJoystickID),		                 // as they are declared above.
	    rightStick(PortAssign::rightJoystickID),	
		roller(PortAssign::rollerID)
	{
		driveTrain.SetExpiration(0.1);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		driveTrain.SetSafetyEnabled(false);
		driveTrain.Drive(-0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		driveTrain.Drive(0.0, 0.0); 	// stop robot
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl()
	{
		driveTrain.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			driveTrain.TankDrive(leftStick, rightStick); // drive with arcade style (use right stick)
			Wait(0.005);				// wait for a motor update time
		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);

