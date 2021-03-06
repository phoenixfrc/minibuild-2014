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
    Gamepadf310 * m_gamePad;
public:

    OurCamera(Servo * pivotMotor, Servo * elevateMotor, Gamepadf310 * gamePadPointer);
    void CameraUpdate();
    virtual ~OurCamera(){};
};



#endif
