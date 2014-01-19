#ifndef GROUPEDBITDEVICE_H
#define GROUPEDBITDEVICE_H

#include "device/DWordDevice.h"
#include "device/BitDevice.h"

#include <vector>
#include <string>
#include <memory>

#include "common/Types.h"

class GroupedBitDevice : public DWordDevice
{
public:
    GroupedBitDevice(const std::vector<std::shared_ptr<BitDevice>> devices);

    virtual ~GroupedBitDevice() {}

    virtual dword getValue() const override;

    virtual void setValue(dword value) override;

protected:

private:
    static std::string computeDeviceName(const std::vector<std::shared_ptr<BitDevice>> devices)
    {
        bool first = true;
        std::string name = "";
        for(auto device : devices)
        {
            if(!first)
                name +=";";
            name += device->getName();
            first = false;
        }
        return name;
    }

    const std::vector<std::shared_ptr<BitDevice>> mModules;
};

#endif // GROUPEDBITDEVICE_H
