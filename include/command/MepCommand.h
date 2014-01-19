#ifndef MEPCOMMAND_H
#define MEPCOMMAND_H

#include "command/Command.h"

class MepCommand : public Command
{
public:
    MepCommand() :
        mOldState(false)
    {}

    virtual ~MepCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    bool mOldState;
};

#endif // MEPCOMMAND_H
