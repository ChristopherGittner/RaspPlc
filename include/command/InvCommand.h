#ifndef INVCOMMAND_H
#define INVCOMMAND_H

#include "command/Command.h"

class InvCommand : public Command
{
public:
    InvCommand() {}

    virtual ~InvCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

};

#endif // INVCOMMAND_H
