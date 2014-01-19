#ifndef TIMER_H
#define TIMER_H

#include "device/BitDevice.h"
#include "device/DWordDevice.h"

#include <string>
#include <chrono>

#include "common/Types.h"

class Timer : public BitDevice, public DWordDevice
{
public:
    Timer(const std::string& name) :
        BitDevice("t" + name),
        DWordDevice("t" + name),
        mStartTime(),
        mDuration()
    {}

    virtual ~Timer() {}

    virtual bool getState() const override;

    virtual void setState(bool state) override;

    virtual dword getValue() const override;

    virtual void setValue(dword value) override;

    virtual std::string print() const override
    {
        return BitDevice::print();
    }

    virtual std::string getName() const override
    {
        return BitDevice::getName();
    }

    void setCurrentTime(const std::chrono::high_resolution_clock::time_point& time = std::chrono::high_resolution_clock::now())
    {
        mCurrentTime = time;
    }
    std::chrono::high_resolution_clock::time_point getCurrentTime() const
    {
        return mCurrentTime;
    }

    void setDuration(const std::chrono::milliseconds duration)
    {
        mDuration = duration;
    }
    std::chrono::milliseconds getDuration() const
    {
        return mDuration;
    }

protected:

private:

    std::chrono::high_resolution_clock::time_point mStartTime;
    std::chrono::high_resolution_clock::time_point mCurrentTime;
    std::chrono::milliseconds mDuration;
};

#endif // TIMER_H
