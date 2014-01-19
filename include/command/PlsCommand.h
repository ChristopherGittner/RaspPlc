#ifndef PLSCOMMAND_H
#define PLSCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class PlsCommand : public Command
{
public:
    PlsCommand(std::shared_ptr<BitDevice> device) :
        Command(),
        mOldState(false),
        mDevice(device)
    {}

    virtual ~PlsCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;


protected:

private:
    bool mOldState;

    std::shared_ptr<BitDevice> mDevice;
};

#endif // PLSCOMMAND_H
