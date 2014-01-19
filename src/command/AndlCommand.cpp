#include "command/AndlCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void AndlCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= (mLeftDevice->getValue() < mRightDevice->getValue());
}

std::string AndlCommand::print()
{
    return "AND< " + mLeftDevice->print() + " " + mRightDevice->print();
}
