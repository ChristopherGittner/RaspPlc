#include "command/OrdCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void OrdCommand::execute(CommandExecutionContext& context)
{
    mDestinationDevice->setValue(mLeftDevice->getValue() ^ mRightDevice->getValue());
}

std::string OrdCommand::print()
{
    return "ORD " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
