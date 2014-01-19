#include "command/LdgCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void LdgCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = (mLeftDevice->getValue() > mRightDevice->getValue());
}

std::string LdgCommand::print()
{
    return "LD> " + mLeftDevice->print() + " " + mRightDevice->print();
}
