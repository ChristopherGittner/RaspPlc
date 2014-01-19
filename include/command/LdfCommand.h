#ifndef LDFCOMMAND_H
#define LDFCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class LdfCommand : public Command
{
public:
    LdfCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device),
        mOldState(false)
    {}

    virtual ~LdfCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
    bool mOldState;
};

#endif // LDFCOMMAND_H
