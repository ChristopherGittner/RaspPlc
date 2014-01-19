#ifndef DIVCOMMAND_H
#define DIVCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class DivCommand : public Command
{
public:
    DivCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice, std::shared_ptr<DWordDevice> destinationDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice),
        mDestinationDevice(destinationDevice)
    {}

    virtual ~DivCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
    std::shared_ptr<DWordDevice> mDestinationDevice;
};

#endif // DIVCOMMAND_H
