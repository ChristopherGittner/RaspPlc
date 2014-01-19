#include "command/LdneCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void LdneCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = (mLeftDevice->getValue() != mRightDevice->getValue());
}

std::string LdneCommand::print()
{
    return "LD<> " + mLeftDevice->print() + " " + mRightDevice->print();
}
