#include "command/LdpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void LdpCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = (mDevice->getState() & !mOldState);
    mOldState = mDevice->getState();
}

std::string LdpCommand::print()
{
    return "LDP " + mDevice->print();
}
