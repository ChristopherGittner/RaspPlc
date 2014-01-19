#include "command/DivpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void DivpCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mDestinationDevice->setValue(mLeftDevice->getValue() / mRightDevice->getValue());
    mOldState = context.Rlo;
}

std::string DivpCommand::print()
{
    return "DIVP " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
