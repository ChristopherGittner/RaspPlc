#ifndef ORCOMMAND_H
#define ORCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class OrCommand : public Command
{
public:
    OrCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device)
    {}

    virtual ~OrCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
};

#endif // ORCOMMAND_H
