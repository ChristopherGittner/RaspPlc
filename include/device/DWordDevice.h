#ifndef WORDDEVICE_H
#define WORDDEVICE_H

#include "device/Device.h"

#include <string>

#include "common/Types.h"

class DWordDevice : public Device
{
public:
    DWordDevice(const std::string& name) :
        Device(name)
    {}

    virtual ~DWordDevice() {}

    virtual dword getValue() const = 0;

    virtual void setValue(dword value) = 0;

protected:

private:

};

#endif // WORDDEVICE_H
