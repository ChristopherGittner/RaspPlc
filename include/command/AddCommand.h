#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class AddCommand : public Command
{
public:

    AddCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice, std::shared_ptr<DWordDevice> destinationDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice),
        mDestinationDevice(destinationDevice)
    {}

    virtual ~AddCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
    std::shared_ptr<DWordDevice> mDestinationDevice;
};

#endif // ADDCOMMAND_H
