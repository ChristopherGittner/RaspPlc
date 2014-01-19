#include "device/Device.h"

#include <algorithm>

std::string Device::print() const
{
    std::string printedName(mName);
    std::transform(printedName.begin(), printedName.end(), printedName.begin(), toupper);
    return printedName;
}
