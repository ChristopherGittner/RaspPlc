#ifndef SETCOMMAND_H
#define SETCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class SetCommand : public Command
{
public:
    SetCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device)
    {}

    virtual ~SetCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;


protected:

private:
    std::shared_ptr<BitDevice> mDevice;
};

#endif // SETCOMMAND_H
