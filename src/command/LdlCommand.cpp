#include "command/LdlCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void LdlCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = (mLeftDevice->getValue() < mRightDevice->getValue());
}

std::string LdlCommand::print()
{
    return "LD< " + mLeftDevice->print() + " " + mRightDevice->print();
}
