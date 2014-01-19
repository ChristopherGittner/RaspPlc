#include "command/EgfCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void EgfCommand::execute(CommandExecutionContext& context)
{
    if(!context.Rlo && mOldState)
        mDevice->setState(true);
    mOldState = context.Rlo;
    context.Rlo &= mDevice->getState();
}

std::string EgfCommand::print()
{
    return "EGF " + mDevice->print();
}
