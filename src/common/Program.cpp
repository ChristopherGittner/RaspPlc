#include "common/Program.h"

#include "command/Command.h"

std::string Program::print()
{
    std::string printout("");

    for(auto command : mCommands)
    {
        printout += command->print() + "\n";
    }

    return printout;
}
