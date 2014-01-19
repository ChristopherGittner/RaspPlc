#include "command/AndpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void AndpCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= (mDevice->getState() & !mOldState);
    mOldState = mDevice->getState();
}

std::string AndpCommand::print()
{
    return "ANDP " + mDevice->print();
}
