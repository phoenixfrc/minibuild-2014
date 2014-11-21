#ifndef ROLL_CTRL_H
#define ROLL_CTRL_H
#include "WPILib.h"
#include "Gamepadf310.h"
#include "PortAssignments.h"

class RollCtrl
{
    static const float inRollSpeed = 0.45;    // pull ball in
    static const float outRollSpeed = -0.40;  // reverse direction
    static const double maxRollTimeSec = 10.0; // seconds
<<<<<<< HEAD

=======
    static const float interval = 0.01; // slope change
    
>>>>>>> 4dcdcdd77948a0e184f040d4d14404bba58205a2
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
    float m_currentSpeed;

public:
    RollCtrl(uint32_t talonPort, Gamepadf310 * gamePadPointer);
    void performRollerTasks();
    void updateState(rollStates dStates);

    virtual ~RollCtrl(){};
};

#endif
