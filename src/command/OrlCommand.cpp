#include "command/OrlCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void OrlCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= (mLeftDevice->getValue() < mRightDevice->getValue());
}

std::string OrlCommand::print()
{
    return "OR< " + mLeftDevice->print() + " " + mRightDevice->print();
}
