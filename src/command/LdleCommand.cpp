#include "command/LdleCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void LdleCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = (mLeftDevice->getValue() <= mRightDevice->getValue());
}

std::string LdleCommand::print()
{
    return "LD<= " + mLeftDevice->print() + " " + mRightDevice->print();
}
