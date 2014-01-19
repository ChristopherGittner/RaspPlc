#include "command/MovpCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void MovpCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo && !mOldState)
        mRightDevice->setValue(mLeftDevice->getValue());
    mOldState = context.Rlo;
}

std::string MovpCommand::print()
{
    return "MOVP " + mLeftDevice->print() + " " + mRightDevice->print();
}
