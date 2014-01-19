#include "command/OriCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void OriCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= !(mDevice->getState());
}

std::string OriCommand::print()
{
    return "ORI " + mDevice->print();
}
