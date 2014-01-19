#include "command/LdCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void LdCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = mDevice->getState();
}

std::string LdCommand::print()
{
    return "LD " + mDevice->print();
}
