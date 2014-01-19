#include "device/SpecialDataRegister.h"

dword SpecialDataRegister::getValue() const
{
    return mValue;
}

void SpecialDataRegister::setValue(dword value)
{
    mValue = value;
}
