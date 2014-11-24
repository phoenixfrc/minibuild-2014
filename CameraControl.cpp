#include "CameraControl.h"

OurCamera::OurCamera(Servo * pivotMotor, Servo * elevateMotor)
{
    m_pivotMotor = pivotMotor;
    m_elevateMotor = elevateMotor;
    m_cameraElevateAngle = 0;
    m_cameraPivotAngle = 0;
}

void OurCamera::CameraUpdate()
{
}
