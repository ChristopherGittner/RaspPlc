#include "command/PlsCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void PlsCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mDevice->setState(true);
    mOldState = context.Rlo;
}

std::string PlsCommand::print()
{
    return "PLS " + mDevice->print();
}
