#include "device/ConstantDWord.h"

#include "common/Exceptions.h"

dword ConstantDWord::getValue() const
{
    return mValue;
}

void ConstantDWord::setValue(dword value)
{
    throw DeviceCannotBeSetException(getName());
}
