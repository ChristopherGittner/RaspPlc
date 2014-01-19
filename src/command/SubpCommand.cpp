#include "command/SubpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void SubpCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mDestinationDevice->setValue(mLeftDevice->getValue() - mRightDevice->getValue());
    mOldState = context.Rlo;
}

std::string SubpCommand::print()
{
    return "SUBP " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
