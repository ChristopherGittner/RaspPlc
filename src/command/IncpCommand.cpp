#include "command/IncpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void IncpCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mDevice->setValue(mDevice->getValue() + 1);
    mOldState = context.Rlo;
}

std::string IncpCommand::print()
{
    return "INCP " + mDevice->print();
}
