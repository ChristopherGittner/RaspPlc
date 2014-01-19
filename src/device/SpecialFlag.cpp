#include "device/SpecialFlag.h"

bool SpecialFlag::getState() const
{
    return mState;
}

void SpecialFlag::setState(bool state)
{
    mState = state;
}
