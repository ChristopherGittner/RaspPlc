#include "command/MulCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void MulCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo)
        mDestinationDevice->setValue(mLeftDevice->getValue() * mRightDevice->getValue());
}

std::string MulCommand::print()
{
    return "MUL " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
