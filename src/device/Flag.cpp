#include "device/Flag.h"

bool Flag::getState() const
{
    return mState;
}

void Flag::setState(bool state)
{
    mState = state;
}
