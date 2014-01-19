#include "command/OrleCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void OrleCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= (mLeftDevice->getValue() <= mRightDevice->getValue());
}

std::string OrleCommand::print()
{
    return "OR<= " + mLeftDevice->print() + " " + mRightDevice->print();
}
