#include "command/AnbCommand.h"

#include "command/CommandExecutionContext.h"

void AnbCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= context.RloStack[context.RloStack.size() - 1];
    context.RloStack.pop_back();
}

std::string AnbCommand::print()
{
    return "ANB";
}
