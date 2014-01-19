#ifndef XORDCOMMAND_H
#define XORDCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class XordCommand : public Command
{
public:
    XordCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice, std::shared_ptr<DWordDevice> destinationDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice),
        mDestinationDevice(destinationDevice)
    {}

    virtual ~XordCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
    std::shared_ptr<DWordDevice> mDestinationDevice;
};

#endif // XORDCOMMAND_H
