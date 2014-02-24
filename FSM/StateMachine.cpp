#include <assert.h>
#include "StateMachine.h"

StateMachine::StateMachine(int maxStates) :
    _maxStates(maxStates),
    currentState(0),
    _eventGenerated(false),
    _pEventData(NULL)
{
}

void StateMachine::ExternalEvent(unsigned char newState, EventData *pData)
{
    if (newState == EVENT_IGNORED) {
        if (pData)
        {
            delete pData;
        }
    } else {
        InternalEvent(newState, pData);
        StateEngine();
    }
}

void StateMachine::InternalEvent(unsigned char newState, EventData *pData)
{
    _pEventData = pData;
    _eventGenerated = true;
    currentState = newState;
}

void StateMachine::StateEngine(void)
{
    EventData *pDataTemp = NULL;

    //lock semaphore here
    //while events are being generated keep executing states
    while (_eventGenerated) {
        pDataTemp = _pEventData;    //copy of event data pointer
        _pEventData = NULL;         //event data used up, reset ptr
        _eventGenerated = false;    //event used up, reset flag

        assert(currentState < _maxStates);

        //execute the state passing in event data, if any
        const StateStruct *pStateMap = GetStateMap();
        (this->*pStateMap[currentState].pStateFunc)(pDataTemp);

        //if event data was used, then delete it
        if (pDataTemp) {
            delete pDataTemp;
            pDataTemp = NULL;
        }
    }
    //unlock semaphore here
}