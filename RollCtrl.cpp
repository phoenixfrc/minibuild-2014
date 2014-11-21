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

    //These will trigger only on the rising-edge of the Button States
    bool X_FirstPress = X_Down && !m_pressedXLast;
    bool Y_FirstPress = Y_Down && !m_pressedYLast;
    bool A_FirstPress = A_Down && !m_pressedALast;
    bool B_FirstPress = B_Down && !m_pressedBLast;

    //Assumptions we're making:
    //A Controls in rolling
    //B Controls out rolling
    //This can be changed later based on mech ideas
    if(A_FirstPress)
    {
        if(m_desiredState == forward)
        {
            m_desiredState = off;
        }
        else
        {    
            m_desiredState = forward;
        }
    }
    if(B_FirstPress)
    {
        if(m_desiredState == backward)
        {
            m_desiredState = off;
        }
        else
        {
            m_desiredState = backward;
        }
    }

    updateState(m_desiredState);
    
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
    m_roller.Set(m_currentSpeed);
}
