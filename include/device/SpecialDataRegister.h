#ifndef SPECIALDATAREGISTER_H
#define SPECIALDATAREGISTER_H

#include "device/DWordDevice.h"

#include <string>

#include "common/Types.h"

class SpecialDataRegister : public DWordDevice
{
public:
    SpecialDataRegister(const std::string& name) :
        DWordDevice("sd" + name),
        mValue(0)
    {}

    virtual ~SpecialDataRegister() {}

    virtual dword getValue() const override;

    virtual void setValue(dword value) override;

protected:

private:

    dword mValue;
};

#endif // SPECIALDATAREGISTER_H
