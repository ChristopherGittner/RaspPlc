#ifndef ORLCOMMAND_H
#define ORLCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class OrlCommand : public Command
{
public:
    OrlCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~OrlCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ORLCOMMAND_H
