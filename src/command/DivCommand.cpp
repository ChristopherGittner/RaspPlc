#include "command/DivCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void DivCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo)
        mDestinationDevice->setValue(mLeftDevice->getValue() / mRightDevice->getValue());
}

std::string DivCommand::print()
{
    return "DIV " + mLeftDevice->print() + " " + mRightDevice->print() + " " + mDestinationDevice->print();
}
