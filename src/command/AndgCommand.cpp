#include "command/AndgCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void AndgCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= (mLeftDevice->getValue() > mRightDevice->getValue());
}

std::string AndgCommand::print()
{
    return "AND> " + mLeftDevice->print() + " " + mRightDevice->print();
}
