#include "command/XordCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void XordCommand::execute(CommandExecutionContext& context)
{
    mDestinationDevice->setValue(mLeftDevice->getValue() ^ mRightDevice->getValue());
}

std::string XordCommand::print()
{
    return "XORD " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
