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
    if (gamePad.GetY() > 0.05 ||
            gamePad.GetY() < -0.05) {
        cameraElevateAngle += gamePad.GetY();
        if (cameraElevateAngle < cameraElevateMotor.GetMinAngle())
            cameraElevateAngle = cameraElevateMotor.GetMinAngle();
        if (cameraElevateAngle > cameraElevateMotor.GetMaxAngle())
            cameraElevateAngle = cameraElevateMotor.GetMaxAngle();
    }
    if (gamePad.GetX() > 0.05 ||
            gamePad.GetX() < -0.05) {
        cameraPivotAngle += gamePad.GetX();
        if (cameraPivotAngle < cameraPivotMotor.GetMinAngle())
            cameraPivotAngle = cameraPivotMotor.GetMinAngle();
        if (cameraPivotAngle > cameraPivotMotor.GetMaxAngle())
            cameraPivotAngle = cameraPivotMotor.GetMaxAngle();
    }
    cameraPivotMotor.SetAngle(cameraPivotAngle);
    cameraElevateMotor.SetAngle(cameraElevateAngle);
}
