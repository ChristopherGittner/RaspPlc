#include "command/AndCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void AndCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= mDevice->getState();
}

std::string AndCommand::print()
{
    return "AND " + mDevice->print();
}
