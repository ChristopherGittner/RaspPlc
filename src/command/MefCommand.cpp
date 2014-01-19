#include "command/MefCommand.h"

#include "command/CommandExecutionContext.h"

void MefCommand::execute(CommandExecutionContext& context)
{
    bool oldState = context.Rlo;
    context.Rlo = (!context.Rlo & mOldState);
    mOldState = oldState;
}

std::string MefCommand::print()
{
    return "MEF";
}
