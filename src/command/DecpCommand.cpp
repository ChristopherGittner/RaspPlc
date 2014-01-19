#include "command/DecpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void DecpCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mDevice->setValue(mDevice->getValue() - 1);
    mOldState = context.Rlo;
}

std::string DecpCommand::print()
{
    return "DECP " + mDevice->print();
}
