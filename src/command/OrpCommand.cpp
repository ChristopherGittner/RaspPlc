#include "command/OrpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void OrpCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= (mDevice->getState() & !mOldState);
    mOldState = mDevice->getState();
}

std::string OrpCommand::print()
{
    return "ORP " + mDevice->print();
}
