#ifndef SPECIALFLAG_H
#define SPECIALFLAG_H

#include <device/BitDevice.h>

#include <string>
#include <iostream>

class SpecialFlag : public BitDevice
{
public:
    SpecialFlag(const std::string& name) :
        BitDevice("sm" + name),
        mState(false)
    {}

    virtual ~SpecialFlag() {}

    virtual bool getState() const override;

    virtual void setState(bool state) override;

protected:

private:
    bool mState;
};

#endif // SPECIALFLAG_H
