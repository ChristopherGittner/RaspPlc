#ifndef FLAG_H
#define FLAG_H

#include <device/BitDevice.h>

#include <string>
#include <iostream>

class Flag : public BitDevice
{
public:
    Flag(const std::string& name) :
        BitDevice("m" + name),
        mState(false)
    {}

    virtual ~Flag() {}

    virtual bool getState() const override;

    virtual void setState(bool state) override;

protected:

private:
    bool mState;
};

#endif // FLAG_H
