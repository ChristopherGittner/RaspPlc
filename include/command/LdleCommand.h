#ifndef LDLECOMMAND_H
#define LDLECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class LdleCommand : public Command
{
public:
    LdleCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~LdleCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // LDLECOMMAND_H
