#include "command/AndfCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void AndfCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= (!mDevice->getState() & mOldState);
    mOldState = mDevice->getState();
}

std::string AndfCommand::print()
{
    return "ANDF " + mDevice->print();
}
