#ifndef CAMERACONTROL_H
#define CAMERACONTROL_H
#include "WPILib.h"

class OurCamera
{
    Servo * m_pivotMotor;
    Servo * m_elevateMotor;
    float m_cameraElevateAngle;
    float m_cameraPivotAngle;
public:
    OurCamera(Servo * pivotMotor, Servo * elevateMotor);
    void CameraUpdate();
    virtual ~OurCamera(){};
};

#endif
