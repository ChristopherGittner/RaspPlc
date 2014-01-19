#include "device/Timer.h"

#include "common/Exceptions.h"

bool Timer::getState() const
{
    return (std::chrono::duration_cast<std::chrono::milliseconds>(mCurrentTime - mStartTime) >= mDuration);
}

void Timer::setState(bool state)
{
    if(state)
        throw DeviceCannotBeSetException(print());
    else
        setValue(0);
}

dword Timer::getValue() const
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(mCurrentTime - mStartTime).count();
}

void Timer::setValue(dword value)
{
    std::chrono::milliseconds ms(value);
    mStartTime = mCurrentTime - ms;
}
