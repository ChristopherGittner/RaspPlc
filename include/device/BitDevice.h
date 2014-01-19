#ifndef BITDEVICE_H
#define BITDEVICE_H

#include "device/Device.h"

#include <string>

class BitDevice : public Device
{
public:
    BitDevice(const std::string& name) :
        Device(name)
    {}

    virtual ~BitDevice() {}

    virtual bool getState() const = 0;

    virtual void setState(bool state) = 0;

protected:

private:
};

#endif // BITDEVICE_H
