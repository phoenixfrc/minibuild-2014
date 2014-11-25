#include "WPILib.h"
#include "PortAssignments.h"
#include "Gamepadf310.h"
#include "RollCtrl.h"
#include "CameraControl.h"

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
    Gamepadf310 gamePad;
    RollCtrl roller;
    Servo cameraPivotMoter;
    Servo cameraElivationMoter;
    OurCamera camera;
public:
    RobotDemo():
        driveTrain(PortAssign::leftMotorChannel, PortAssign::rightMotorChannel), // these must be initialized in the same order
        leftStick(PortAssign::leftJoystickID),		                 // as they are declared above.
        rightStick(PortAssign::rightJoystickID),
        gamePad(PortAssign::gamePadID),
        roller(PortAssign::rollerChannel, &gamePad),
        cameraPivotMoter(PortAssign::cameraPivotPort),
        cameraElivationMoter(PortAssign::cameraElivationPort),
        camera(&cameraPivotMoter,&cameraElivationMoter,&gamePad)
        
    {
        driveTrain.SetExpiration(0.1);
    }

    /**
     * Drive left & right motors for 2 seconds then stop
     */
    void Autonomous()
    {
        driveTrain.Drive(-0.5, 0.0); 	// drive forwards half speed

        driveTrain.SetSafetyEnabled(false);
        Wait(2.0); 				//    for 2 seconds
        driveTrain.Drive(0.0, 0.0); 	// stop robot

        driveTrain.SetSafetyEnabled(true);
    }

    /**
     * Runs the motors with arcade steering. 
     */
    void OperatorControl()
    {
        driveTrain.SetSafetyEnabled(true);
        while (IsOperatorControl())
        {
            driveTrain.TankDrive(leftStick, rightStick); // drive with tankdrive
            roller.performRollerTasks();
            camera.CameraUpdate();
            Wait(RobotConstants::teleopPauseDelaySec);   // wait for a motor update time
        }
    }

    /**
     * Runs during test mode
     */
    void Test() {

    }
};

START_ROBOT_CLASS(RobotDemo);

