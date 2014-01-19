#include "command/RstCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void RstCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo)
        mDevice->setState(false);
}

std::string RstCommand::print()
{
    return "RST " + mDevice->print();
}
