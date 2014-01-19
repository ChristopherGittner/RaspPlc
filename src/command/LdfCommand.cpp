#include "command/LdfCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void LdfCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = (!mDevice->getState() & mOldState);
    mOldState = mDevice->getState();
}

std::string LdfCommand::print()
{
    return "LDF " + mDevice->print();
}
