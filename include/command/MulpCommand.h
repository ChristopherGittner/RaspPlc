#ifndef MULPCOMMAND_H
#define MULPCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class MulpCommand : public Command
{
public:
    MulpCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice, std::shared_ptr<DWordDevice> destinationDevice) :
        Command(),
        mOldState(false),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice),
        mDestinationDevice(destinationDevice)
    {}

    virtual ~MulpCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    bool mOldState;

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
    std::shared_ptr<DWordDevice> mDestinationDevice;
};

#endif // MULPCOMMAND_H
