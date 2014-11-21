#ifndef PORT_ASSIGN_H
#define PORT_ASSIGN_H

struct PortAssign
{
    //Motor Ports
    static const int leftMotorChannel = 4;//port 4 because port 1 doesn't work
    static const int rightMotorChannel = 2;
    static const int rollerChannel = 3;
    //Joystick Ports
    static const int leftJoystickID  = 1;
    static const int rightJoystickID = 2;
    static const int gamePadID = 3;
    //camera ports
    static const int cameraPivotPort = 9;
    static const int cameraElivationPort = 10; 
};

struct RobotConstants
{
    static const double teleopPauseDelaySec = 0.005; // main teleop loop delay time
};

#endif
