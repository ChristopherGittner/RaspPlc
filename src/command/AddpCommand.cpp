#include "command/AddpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void AddpCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mDestinationDevice->setValue(mLeftDevice->getValue() + mRightDevice->getValue());
    mOldState = context.Rlo;
}

std::string AddpCommand::print()
{
    return "ADDP " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
