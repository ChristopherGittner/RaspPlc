#ifndef ANDNECOMMAND_H
#define ANDNECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class AndneCommand : public Command
{
public:
    AndneCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~AndneCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ANDNECOMMAND_H
