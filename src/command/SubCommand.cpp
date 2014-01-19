#include "command/SubCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void SubCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo)
        mDestinationDevice->setValue(mLeftDevice->getValue() - mRightDevice->getValue());
}

std::string SubCommand::print()
{
    return "SUB " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
