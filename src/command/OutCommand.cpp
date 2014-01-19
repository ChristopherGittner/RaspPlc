#include "command/OutCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void OutCommand::execute(CommandExecutionContext& context)
{
    mDevice->setState(context.Rlo);
}

std::string OutCommand::print()
{
    return "OUT " + mDevice->print();
}
