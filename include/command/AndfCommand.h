#ifndef ANDFCOMMAND_H
#define ANDFCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class AndfCommand : public Command
{
public:
    AndfCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device),
        mOldState(false)
    {}

    virtual ~AndfCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
    bool mOldState;
};

#endif // ANDFCOMMAND_H
