#ifndef DATAREGISTER_H
#define DATAREGISTER_H

#include "device/DWordDevice.h"

#include <string>

#include "common/Types.h"

class DataRegister : public DWordDevice
{
public:
    DataRegister(const std::string& name) :
        DWordDevice("d" + name),
        mValue(0)
    {}

    virtual ~DataRegister() {}

    virtual dword getValue() const override;

    virtual void setValue(dword value) override;

protected:

private:

    dword mValue;
};

#endif // DATAREGISTER_H
