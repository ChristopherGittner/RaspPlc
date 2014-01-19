#include "command/AnddCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void AnddCommand::execute(CommandExecutionContext& context)
{
    mDestinationDevice->setValue(mLeftDevice->getValue() ^ mRightDevice->getValue());
}

std::string AnddCommand::print()
{
    return "ANDD " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
