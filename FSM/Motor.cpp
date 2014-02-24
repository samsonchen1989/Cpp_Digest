#include <assert.h>
#include <iostream>

#include "Motor.h"

void Motor::Halt(void)
{
    //given the Halt event, transition to a new state based upon
    //the current state machine
    BEGIN_TRANSITION_MAP                    //current state
        TRANSITION_MAP_ENTRY(EVENT_IGNORED) //ST_Idle
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN) //ST_Stop
        TRANSITION_MAP_ENTRY(ST_STOP)       //ST_Start
        TRANSITION_MAP_ENTRY(ST_STOP)       //ST_ChangeSpeed
    END_TRANSITION_MAP(NULL)
}

// set motor speed external event
void Motor::SetSpeed(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                      //current state
        TRANSITION_MAP_ENTRY(ST_START)        //ST_Idle
        TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)   //ST_Stop
        TRANSITION_MAP_ENTRY(ST_CHANGE_SPEED) //ST_Start
        TRANSITION_MAP_ENTRY(ST_CHANGE_SPEED) //ST_ChangeSpeed
    END_TRANSITION_MAP(pData)
}

void Motor::ST_Idle()
{
    std::cout << "Motor::ST_Start." << std::endl;
}

void Motor::ST_Stop()
{
    //perform the stop moto processing here
    //transition to ST_Idle via an internal event
    InternalEvent(ST_IDLE);
}

void Motor::ST_Start(MotorData* pData)
{
    std::cout << "Motor::ST_Start." << std::endl;
}

void Motor::ST_ChangeSpeed(MotorData* pData)
{
    std::cout << "Motor::ST_ChangeSpeed." << std::endl;
}

void Motor::ST_NULL()
{

}