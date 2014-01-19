#ifndef MPSCOMMAND_H
#define MPSCOMMAND_H

#include "command/Command.h"

class MpsCommand : public Command
{
public:
    MpsCommand() {}

    virtual ~MpsCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

};

#endif // MPSCOMMAND_H
