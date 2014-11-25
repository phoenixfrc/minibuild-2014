#include "CameraControl.h"

OurCamera::OurCamera(Servo * pivotMotor, Servo * elevateMotor)
{
    m_pivotMotor = pivotMotor;
    m_elevateMotor = elevateMotor;
    m_cameraElevateAngle = 0;
    m_cameraPivotAngle = 0;
}

void OurCamera::CameraUpdate(Gamepadf310 gamePad)
{
    if (gamePad.GetY() > 0.05 ||
            gamePad.GetY() < -0.05) {
        m_cameraElevateAngle += gamePad.GetY();
        if (m_cameraElevateAngle < m_elevateMotor->GetMinAngle())
            m_cameraElevateAngle = m_elevateMotor->GetMinAngle();
        if (m_cameraElevateAngle > m_elevateMotor->GetMaxAngle())
            m_cameraElevateAngle = m_elevateMotor->GetMaxAngle();
    }
    if (gamePad.GetX() > 0.05 ||
            gamePad.GetX() < -0.05) {
        m_cameraPivotAngle += gamePad.GetX();
        if (m_cameraPivotAngle < m_pivotMotor->GetMinAngle())
            m_cameraPivotAngle = m_pivotMotor->GetMinAngle();
        if (m_cameraPivotAngle > m_pivotMotor->GetMaxAngle())
            m_cameraPivotAngle = m_pivotMotor->GetMaxAngle();
    }
    m_pivotMotor->SetAngle(m_cameraPivotAngle);
    m_elevateMotor->SetAngle(m_cameraElevateAngle);

}
