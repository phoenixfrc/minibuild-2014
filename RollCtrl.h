#ifndef ROLL_CTRL_H
#define ROLL_CTRL_H
#include "WPILib.h"
#include "Gamepadf310.h"

class RollCtrl
{
	Talon roller;
	Joystick * gamePad;
public:
	RollCtrl(uint32_t talonPort, Joystick * gamePadPointer);
	virtual ~RollCtrl(){};
};

#endif
