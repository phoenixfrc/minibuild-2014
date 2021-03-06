#include "CameraControl.h"

OurCamera::OurCamera(Servo * pivotMotor, Servo * elevateMotor, Gamepadf310 * gamePadPointer)
{
    m_pivotMotor = pivotMotor;
    m_elevateMotor = elevateMotor;
    m_cameraElevateAngle = 0;
    m_cameraPivotAngle = 0;
    m_pivotMotor->SetAngle(m_cameraPivotAngle); //setting initial angles for the motors
    m_elevateMotor->SetAngle(m_cameraElevateAngle);
    m_gamePad = gamePadPointer;
}

void OurCamera::CameraUpdate()
{
    if (m_gamePad->GetY() > 0.05 ||
            m_gamePad->GetY() < -0.05) {
        m_cameraElevateAngle += m_gamePad->GetY();
        if (m_cameraElevateAngle < m_elevateMotor->GetMinAngle())
            m_cameraElevateAngle = m_elevateMotor->GetMinAngle();
        if (m_cameraElevateAngle > m_elevateMotor->GetMaxAngle())
            m_cameraElevateAngle = m_elevateMotor->GetMaxAngle();
    }
    if (m_gamePad->GetX() > 0.05 ||
            m_gamePad->GetX() < -0.05) {
        m_cameraPivotAngle += m_gamePad->GetX();
        if (m_cameraPivotAngle < m_pivotMotor->GetMinAngle())
            m_cameraPivotAngle = m_pivotMotor->GetMinAngle();
        if (m_cameraPivotAngle > m_pivotMotor->GetMaxAngle())
            m_cameraPivotAngle = m_pivotMotor->GetMaxAngle();
    }
    m_pivotMotor->SetAngle(m_cameraPivotAngle);
    m_elevateMotor->SetAngle(m_cameraElevateAngle);

}
