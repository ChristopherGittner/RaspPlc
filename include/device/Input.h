#ifndef INPUT_H
#define INPUT_H

#include <device/BitDevice.h>

#include <string>
#include <iostream>

class Input : public BitDevice
{
public:
    Input(const std::string& name) :
        BitDevice("x" + name),
        mState(false)
    {}

    virtual ~Input() {}

    virtual bool getState() const override;

    virtual void setState(bool state) override;

protected:

private:
    bool mState;
};

#endif // INPUT_H
