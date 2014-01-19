#include "command/PlfCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void PlfCommand::execute(CommandExecutionContext& context)
{
    if(!context.Rlo && mOldState)
        mDevice->setState(true);
    mOldState = context.Rlo;
}

std::string PlfCommand::print()
{
    return "PLF " + mDevice->print();
}
