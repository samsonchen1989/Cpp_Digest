#include "Motor.h"

int main(int argc, char** argv)
{
    Motor myMotor;

    MotorData *pData = new MotorData;
    pData->speed = 50;
    myMotor.SetSpeed(pData);

    myMotor.Halt();

    return 0;
}
