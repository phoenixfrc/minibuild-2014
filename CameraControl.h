#ifndef CAMERACONTROL_H
#define CAMERACONTROL_H
#include "WPILib.h"
#include "Gamepadf310.h"

class OurCamera
{
    Servo * m_pivotMotor;
    Servo * m_elevateMotor;
    float m_cameraElevateAngle;
    float m_cameraPivotAngle;

public:

    OurCamera(Servo * pivotMotor, Servo * elevateMotor);
    void CameraUpdate(Gamepadf310 gamePad);
    virtual ~OurCamera(){};
};



#endif
