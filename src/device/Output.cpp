#include "device/Output.h"

bool Output::getState() const
{
    return mState;
}

void Output::setState(bool state)
{
    mState = state;
}
