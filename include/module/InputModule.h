#ifndef INPUTMODULE_H
#define INPUTMODULE_H

#include <memory>

class DWordDevice;

class InputModule
{
public:
    InputModule(std::shared_ptr<DWordDevice> inDevice) :
        mInDevice(inDevice)
    {}

    virtual ~InputModule() {}

    std::shared_ptr<DWordDevice> getDevice()
    {
        return mInDevice;
    }

    virtual void readFromModule() = 0;

protected:
    std::shared_ptr<DWordDevice> mInDevice;

private:
};

#endif // INPUTMODULE_H
