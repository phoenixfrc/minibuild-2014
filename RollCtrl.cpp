#include "RollCtrl.h"

RollCtrl::RollCtrl(uint32_t talonPort, Gamepadf310 * gamePadPointer):
m_roller(talonPort), m_remainingRollTimeSec(0.0)
{
    m_gamePad = gamePadPointer;
    m_desiredState = off;
    m_pressedALast = false;
    m_pressedBLast = false;
    m_pressedXLast = false;
    m_pressedYLast = false;
    m_currentSpeed = 0;
}

void RollCtrl::performRollerTasks()
{
    //Gather inputs and make them typist-friendly
    bool X_Down = m_gamePad->GetRawButton(Gamepadf310::X);
    bool Y_Down = m_gamePad->GetRawButton(Gamepadf310::Y);
    bool A_Down = m_gamePad->GetRawButton(Gamepadf310::A);
    bool B_Down = m_gamePad->GetRawButton(Gamepadf310::B);

    //Getting these ready, these viariables are only true during the first
    //iteration when a button is pressed (this way we only perform an action once)
    bool X_Pressed = X_Down;
    bool Y_Pressed = Y_Down;
    bool A_Pressed = A_Down;
    bool B_Pressed = B_Down;

    //Tests to set the value of these variables
    if(!m_pressedALast && A_Down)
    {
        A_Pressed = true;
    }
    if(m_pressedALast && A_Down)
    {
        A_Pressed = false;
    }
    if(!m_pressedBLast && B_Down)
    {
        B_Pressed = true;
    }
    if(m_pressedBLast && B_Down)
    {
        B_Pressed = false;
    }
    if(!m_pressedXLast && X_Down)
    {
        X_Pressed = true;
    }
    if(m_pressedXLast && X_Down)
    {
        X_Pressed = false;
    }
    if(!m_pressedYLast && Y_Down)
    {
        Y_Pressed = true;
    }
    if(m_pressedYLast && Y_Down)
    {
        Y_Pressed = false;
    }

    //Assumptions we're making:
    //A Controls out rolling
    //B Controls in rolling
    //This can be changed later based on mech ideas
    if (A_Down) {
        m_roller.Set(outRollSpeed);
        m_remainingRollTimeSec = maxRollTimeSec;
    } else if (B_Down) {
        m_roller.Set(inRollSpeed);
        m_remainingRollTimeSec = maxRollTimeSec;
    } else if (m_remainingRollTimeSec > 0.0) {
        m_remainingRollTimeSec -= RobotConstants::teleopPauseDelaySec;
    } else {
        m_roller.StopMotor();
    }

    //Setting up variables for next iteration
    m_pressedALast = A_Down;
    m_pressedBLast = B_Down;
    m_pressedXLast = X_Down;
    m_pressedYLast = Y_Down;
}

void RollCtrl::updateState(rollStates dState)
{
    // off code
    if(dState == off)
    {
        if (m_currentSpeed < -interval)
        {
            m_currentSpeed += interval;
        }
        else if (m_currentSpeed > interval)
        {
            m_currentSpeed -= interval;
        }
        else
        {
            m_currentSpeed = 0;
        }
    }

    // forward code
    if(dState == forward)
    {
        if (m_currentSpeed < inRollSpeed - interval)
        {
            m_currentSpeed += interval;
        }
        else
        {
            m_currentSpeed = inRollSpeed;
        }
    }

    // backward code

    if(dState == backward)
    {
        if (m_currentSpeed > outRollSpeed + interval)
        {
            m_currentSpeed -= interval;
        }
        else
        {
            m_currentSpeed = outRollSpeed;
        }
    }
    m_roller.set(m_currentSpeed);
}