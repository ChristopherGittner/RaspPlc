#include "command/AddCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void AddCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo)
        mDestinationDevice->setValue(mLeftDevice->getValue() + mRightDevice->getValue());
}

std::string AddCommand::print()
{
    return "ADD " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
