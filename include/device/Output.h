#ifndef OUTPUT_H
#define OUTPUT_H

#include <device/BitDevice.h>

#include <string>

class Output : public BitDevice
{
public:
    Output(const std::string& name) :
        BitDevice("y" + name),
        mState(false)
    {}

    virtual ~Output() {}

    virtual bool getState() const override;

    virtual void setState(bool state) override;

protected:

private:
    bool mState;
};

#endif // OUTPUT_H
