#include "command/AndleCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void AndleCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= (mLeftDevice->getValue() <= mRightDevice->getValue());
}

std::string AndleCommand::print()
{
    return "AND<= " + mLeftDevice->print() + " " + mRightDevice->print();
}
