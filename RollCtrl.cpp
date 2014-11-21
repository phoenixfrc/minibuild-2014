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

    //Getting these ready, these viariables are only true during the first
    //iteration when a button is pressed (this way we only perform an action once)
    bool X_Pressed = false;
    bool Y_Pressed = false;
    bool A_Pressed = false;
    bool B_Pressed = false;

    //Tests to set the value of these variables
    if(A_Down)
    {
    	A_Pressed = !m_pressedALast;
    }
    if(B_Down)
    {
    	B_Pressed = !m_pressedBLast;
    }
    if(X_Down)
    {
    	X_Pressed = !m_pressedXLast;
    }
    if(Y_Down)
    {
    	Y_Pressed = !m_pressedYLast;
    }

    //Assumptions we're making:
    //A Controls out rolling
    //B Controls in rolling
    //This can be changed later based on mech ideas
    if(A_Pressed)
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
    if(B_Pressed)
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
