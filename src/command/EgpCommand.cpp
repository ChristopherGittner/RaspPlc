#include "command/EgpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void EgpCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mDevice->setState(true);
    mOldState = context.Rlo;
    context.Rlo &= mDevice->getState();
}

std::string EgpCommand::print()
{
    return "EGP " + mDevice->print();
}
