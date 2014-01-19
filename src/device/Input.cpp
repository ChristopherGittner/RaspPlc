#include "device/Input.h"

bool Input::getState() const
{
    return mState;
}

void Input::setState(bool state)
{
    mState = state;
}
