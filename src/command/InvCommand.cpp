#include "command/InvCommand.h"

#include "command/CommandExecutionContext.h"

void InvCommand::execute(CommandExecutionContext& context)
{
    context.Rlo = !context.Rlo;
}

std::string InvCommand::print()
{
    return "INV";
}
