#ifndef ANDLECOMMAND_H
#define ANDLECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class AndleCommand : public Command
{
public:
    AndleCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~AndleCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ANDLECOMMAND_H
