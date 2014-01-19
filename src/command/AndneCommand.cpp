#include "command/AndneCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void AndneCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= (mLeftDevice->getValue() != mRightDevice->getValue());
}

std::string AndneCommand::print()
{
    return "AND<> " + mLeftDevice->print() + " " + mRightDevice->print();
}
