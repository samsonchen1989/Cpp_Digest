#ifndef MOTOR_H
#define MOTOR_H
#include "StateMachine.h"

//structure to hold event machine class
struct MotorData : public EventData
{
    int speed;
};

//the Motor state machine class
class Motor : public StateMachine
{
public:
    Motor() : StateMachine(ST_MAX_STATES) {};
    // external events taken by this state machine
    void Halt();
    void SetSpeed(MotorData*);
private:
    //state machine state functions
    void ST_Idle();
    void ST_Stop();
    void ST_Start(MotorData*);
    void ST_ChangeSpeed(MotorData*);
    void ST_NULL();

    //state map to define state function order
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&Motor::ST_Idle)
        STATE_MAP_ENTRY(&Motor::ST_Stop)
        STATE_MAP_ENTRY(&Motor::ST_Start)
        STATE_MAP_ENTRY(&Motor::ST_ChangeSpeed)
    END_STATE_MAP(&Motor::ST_NULL)

    //state enumeration order must match the order of state
    //method entries in the state map
    enum E_States {
        ST_IDLE = 0,
        ST_STOP,
        ST_START,
        ST_CHANGE_SPEED,
        ST_MAX_STATES
    };
};

#endif