#include "command/FfCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void FfCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mDevice->setState(!mDevice->getState());
    mOldState = context.Rlo;
}

std::string FfCommand::print()
{
    return "FF " + mDevice->print();
}
