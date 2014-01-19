#ifndef ORLECOMMAND_H
#define ORLECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class OrleCommand : public Command
{
public:
    OrleCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~OrleCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ORLECOMMAND_H
