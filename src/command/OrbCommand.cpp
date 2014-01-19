#include "command/OrbCommand.h"

#include "command/CommandExecutionContext.h"

void OrbCommand::execute(CommandExecutionContext& context)
{
    context.Rlo |= context.RloStack[context.RloStack.size() - 1];
    context.RloStack.pop_back();
}

std::string OrbCommand::print()
{
    return "ORB";
}
