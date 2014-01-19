#include "command/OreCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void OreCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= (mLeftDevice->getValue() == mRightDevice->getValue());
}

std::string OreCommand::print()
{
    return "OR= " + mLeftDevice->print() + " " + mRightDevice->print();
}
