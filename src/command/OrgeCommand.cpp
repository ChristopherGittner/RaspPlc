#include "command/OrgeCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void OrgeCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= (mLeftDevice->getValue() >= mRightDevice->getValue());
}

std::string OrgeCommand::print()
{
    return "OR>= " + mLeftDevice->print() + " " + mRightDevice->print();
}
