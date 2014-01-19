#include "device/GroupedBitDevice.h"

#include <math.h>

#include <common/Exceptions.h>

GroupedBitDevice::GroupedBitDevice(const std::vector<std::shared_ptr<BitDevice>> devices) :
    DWordDevice(computeDeviceName(devices)),
    mModules(devices)
{
    if(devices.size() == 0)
        throw InvalidArgumentException("GroupedBitDevice::GroupedBitDevice devices.size() == 0");
    if(devices.size() > 32)
        throw InvalidArgumentException("GroupedBitDevice::GroupedBitDevice devices.size() > 32");
}

dword GroupedBitDevice::getValue() const
{
    int offset = 1;
    word value = 0;

    for(auto device : mModules)
    {
        if(device->getState())
            value += offset;
        offset *= 2;
    }

    return value;
}

void GroupedBitDevice::setValue(dword value)
{
    dword mask = (pow(2, mModules.size())) - 1;
    value &= mask;

    for(auto i = mModules.begin(); i != mModules.end(); ++i)
    {
        mask = pow(2, i - mModules.begin());
        (*i)->setState(value & mask);
    }
}
