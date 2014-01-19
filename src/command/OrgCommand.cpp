#include "command/OrgCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void OrgCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= (mLeftDevice->getValue() > mRightDevice->getValue());
}

std::string OrgCommand::print()
{
    return "OR> " + mLeftDevice->print() + " " + mRightDevice->print();
}
