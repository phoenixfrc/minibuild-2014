#include "RollCtrl.h"
#include "Gamepadf310.h"

RollCtrl::RollCtrl(uint32_t talonPort, Joystick * gamePadPointer):
	roller(talonPort)
{
	gamePad = gamePadPointer;
}
