#include "command/IncCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void IncCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo)
        mDevice->setValue(mDevice->getValue() + 1);
}

std::string IncCommand::print()
{
    return "INC " + mDevice->print();
}
