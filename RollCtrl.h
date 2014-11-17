#ifndef ROLL_CTRL_H
#define ROLL_CTRL_H
#include "WPILib.h"
#include "Gamepadf310.h"

class RollCtrl
{
	static const float pullRollSpeed = 0.75;
	static const float pushRollSpeed = 0.75;
	enum rollStates
	{
		forward,
		backward,
		off
	};
	rollStates m_desiredState;
	Talon m_roller;
	Gamepadf310 * m_gamePad;
	bool m_pressedALast;
	bool m_pressedBLast;
	bool m_pressedXLast;
	bool m_pressedYLast;
public:
	RollCtrl(uint32_t talonPort, Gamepadf310 * gamePadPointer);
	void performRollerTasks();
	virtual ~RollCtrl(){};
};

#endif
