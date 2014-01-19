#include "command/OrfCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void OrfCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= (!mDevice->getState() & mOldState);
    mOldState = mDevice->getState();
}

std::string OrfCommand::print()
{
    return "ORF " + mDevice->print();
}
