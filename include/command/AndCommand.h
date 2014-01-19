#ifndef ANDCOMMAND_H
#define ANDCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class AndCommand : public Command
{
public:
    AndCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device)
    {}

    virtual ~AndCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
};

#endif // ANDCOMMAND_H
