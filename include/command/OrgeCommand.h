#ifndef ORGECOMMAND_H
#define ORGECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class OrgeCommand : public Command
{
public:
    OrgeCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~OrgeCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ORGECOMMAND_H
