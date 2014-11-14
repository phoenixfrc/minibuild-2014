#include "RollCtrl.h"
#include "Gamepadf310.h"

RollCtrl::RollCtrl(uint32_t talonPort, Gamepadf310 * gamePadPointer):
	m_roller(talonPort)
{
	m_gamePad = gamePadPointer;
}

void RollCtrl::performRollerTasks()
{
	
}
