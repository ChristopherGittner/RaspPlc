#include "device/DataRegister.h"

dword DataRegister::getValue() const
{
    return mValue;
}

void DataRegister::setValue(dword value)
{
    mValue = value;
}
