#ifndef MEFCOMMAND_H
#define MEFCOMMAND_H

#include "command/Command.h"

class MefCommand : public Command
{
public:
    MefCommand() :
        mOldState(false)
    {}

    virtual ~MefCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    bool mOldState;
};

#endif // MEFCOMMAND_H
