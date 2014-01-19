#ifndef MRDCOMMAND_H
#define MRDCOMMAND_H

#include "command/Command.h"

class MrdCommand : public Command
{
public:
    MrdCommand() {}

    virtual ~MrdCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

};

#endif // MRDCOMMAND_H
