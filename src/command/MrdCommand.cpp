#include "command/MrdCommand.h"

#include "command/CommandExecutionContext.h"

void MrdCommand::execute(CommandExecutionContext& context)
{
    context.Rlo = context.RloStack[context.RloStack.size() - 1];
}

std::string MrdCommand::print()
{
    return "MRD";
}
