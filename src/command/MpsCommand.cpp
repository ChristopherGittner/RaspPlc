#include "command/MpsCommand.h"

#include "command/CommandExecutionContext.h"

void MpsCommand::execute(CommandExecutionContext& context)
{
    context.RloStack.push_back(context.Rlo);
}

std::string MpsCommand::print()
{
    return "MPS";
}
