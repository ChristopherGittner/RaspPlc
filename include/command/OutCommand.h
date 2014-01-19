#ifndef OUTCOMMAND_H
#define OUTCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class OutCommand : public Command
{
public:
    OutCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device)
    {}

    virtual ~OutCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
};

#endif // OUTCOMMAND_H
