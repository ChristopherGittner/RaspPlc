#include "command/SetCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void SetCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo)
        mDevice->setState(true);
}

std::string SetCommand::print()
{
    return "SET " + mDevice->print();
}
