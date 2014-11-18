#ifndef GAMEPADF310_H
#define GAMEPADF310_H
#include "WPILib.h"
class Gamepadf310 : public Joystick
{
public:
    explicit Gamepadf310(uint32_t port);
    Gamepadf310(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes);
    virtual ~Gamepadf310();
    static const int X = 1;
    static const int Y = 4;
    static const int A = 2;
    static const int B = 3;
};
#endif
