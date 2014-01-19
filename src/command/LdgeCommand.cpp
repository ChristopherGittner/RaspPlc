#include "command/LdgeCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void LdgeCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = (mLeftDevice->getValue() >= mRightDevice->getValue());
}

std::string LdgeCommand::print()
{
    return "LD>= " + mLeftDevice->print() + " " + mRightDevice->print();
}
