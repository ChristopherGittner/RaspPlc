#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class CommandExecutionContext;

class Command
{
public:
    Command() {}
    virtual ~Command() {}

    virtual void execute(CommandExecutionContext& context) = 0;
    virtual std::string print() = 0;

protected:
private:
};

#endif // COMMAND_H
