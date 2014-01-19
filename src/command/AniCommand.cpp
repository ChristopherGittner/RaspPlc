#include "command/AniCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"

void AniCommand::execute(CommandExecutionContext& context)
{
    context.Rlo &= !(mDevice->getState());
}

std::string AniCommand::print()
{
    return "ANI " + mDevice->print();
}
