#include "command/AndgeCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void AndgeCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= (mLeftDevice->getValue() >= mRightDevice->getValue());
}

std::string AndgeCommand::print()
{
    return "AND>= " + mLeftDevice->print() + " " + mRightDevice->print();
}
