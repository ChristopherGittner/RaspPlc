#include "command/MppCommand.h"

#include "command/CommandExecutionContext.h"

void MppCommand::execute(CommandExecutionContext& context)
{
    context.Rlo = context.RloStack[context.RloStack.size() - 1];
    context.RloStack.pop_back();
}

std::string MppCommand::print()
{
    return "MPP";
}
