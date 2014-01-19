#ifndef ORICOMMAND_H
#define ORICOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class OriCommand : public Command
{
public:
    OriCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device)
    {}

    virtual ~OriCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
};

#endif // ORICOMMAND_H
