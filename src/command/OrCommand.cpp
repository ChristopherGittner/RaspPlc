#include "command/OrCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void OrCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= mDevice->getState();
}

std::string OrCommand::print()
{
    return "OR " + mDevice->print();
}
