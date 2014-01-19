#include "command/OrneCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void OrneCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= (mLeftDevice->getValue() != mRightDevice->getValue());
}

std::string OrneCommand::print()
{
    return "OR<> " + mLeftDevice->print() + " " + mRightDevice->print();
}
