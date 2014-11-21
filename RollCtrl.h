#ifndef ROLL_CTRL_H
#define ROLL_CTRL_H
#include "WPILib.h"
#include "Gamepadf310.h"
#include "PortAssignments.h"

class RollCtrl
{
    static const float inRollSpeed = 0.45;    // pull ball in
    static const float outRollSpeed = -0.45;  // reverse direction
    static const double maxRollTimeSec = 10.0; // seconds

    enum rollStates
    {
        forward,
        backward,
        off
    };
    rollStates m_desiredState;
    Talon m_roller;
    double m_remainingRollTimeSec;  // time remaining before roller shutoff in seconds

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
