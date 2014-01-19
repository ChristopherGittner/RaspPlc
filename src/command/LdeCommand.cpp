#include "command/LdeCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void LdeCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = (mLeftDevice->getValue() == mRightDevice->getValue());
}

std::string LdeCommand::print()
{
    return "LD= " + mLeftDevice->print() + " " + mRightDevice->print();
}
