#ifndef INCPCOMMAND_H
#define INCPCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class IncpCommand : public Command
{
public:
    IncpCommand(std::shared_ptr<DWordDevice> device) :
        Command(),
        mOldState(false),
        mDevice(device)
    {}

    virtual ~IncpCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    bool mOldState;

    std::shared_ptr<DWordDevice> mDevice;
};

#endif // INCPCOMMAND_H
