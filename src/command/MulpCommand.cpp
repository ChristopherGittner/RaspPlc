#include "command/MulpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void MulpCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mDestinationDevice->setValue(mLeftDevice->getValue() * mRightDevice->getValue());
    mOldState = context.Rlo;
}

std::string MulpCommand::print()
{
    return "MULP " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
