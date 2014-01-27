#include "command/LdiCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void LdiCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
    context.Rlo = !(mDevice->getState());
}

std::string LdiCommand::print()
{
    return "LDI " + mDevice->print();
}
