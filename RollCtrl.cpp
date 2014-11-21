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

    //Setting up variables for next iteration
    m_pressedALast = A_Down;
    m_pressedBLast = B_Down;
    m_pressedXLast = X_Down;
    m_pressedYLast = Y_Down;
}
