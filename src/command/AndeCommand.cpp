#include "command/AndeCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void AndeCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= (mLeftDevice->getValue() == mRightDevice->getValue());
}

std::string AndeCommand::print()
{
    return "AND= " + mLeftDevice->print() + " " + mRightDevice->print();
}
