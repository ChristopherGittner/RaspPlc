#ifndef ORNECOMMAND_H
#define ORNECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class OrneCommand : public Command
{
public:
    OrneCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~OrneCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ORNECOMMAND_H
