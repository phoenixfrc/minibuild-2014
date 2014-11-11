#ifndef GAMEPADF310_H
#define GAMEPADF310_H
#include "WPILib.h"
class Gamepadf310 : public Joystick
{
	explicit Gamepadf310(uint32_t port);
	Gamepadf310(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes);
	virtual ~Gamepadf310();
};
#endif
