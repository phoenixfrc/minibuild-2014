#include "RollCtrl.h"
#include "Gamepadf310.h"

RollCtrl::RollCtrl(uint32_t talonPort, Gamepadf310 * gamePadPointer):
	m_roller(talonPort)
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
	bool X_Pressed;
	bool Y_Pressed;
	bool A_Pressed;
	bool B_Pressed;
	
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
	//A Controls forward rolling
	//B Controls backwards rolling
	//This can be changed later based on mech ideas
	
	//Setting up variables for next iteration
	m_pressedALast = A_Down;
	m_pressedBLast = B_Down;
	m_pressedXLast = X_Down;
	m_pressedYLast = Y_Down;
}
