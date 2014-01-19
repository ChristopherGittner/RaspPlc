#ifndef MPPCOMMAND_H
#define MPPCOMMAND_H

#include "command/Command.h"

class MppCommand : public Command
{
public:
    MppCommand() {}

    virtual ~MppCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

};

#endif // MPPCOMMAND_H
