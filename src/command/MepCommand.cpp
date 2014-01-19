#include "command/MepCommand.h"

#include "command/CommandExecutionContext.h"

void MepCommand::execute(CommandExecutionContext& context)
{
    bool oldState = context.Rlo;
    context.Rlo &= !mOldState;
    mOldState = oldState;
}

std::string MepCommand::print()
{
    return "MEP";
}
