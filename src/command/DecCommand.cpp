#include "command/DecCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void DecCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo)
        mDevice->setValue(mDevice->getValue() - 1);
}

std::string DecCommand::print()
{
    return "DEC " + mDevice->print();
}
