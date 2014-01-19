#ifndef ORGCOMMAND_H
#define ORGCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class OrgCommand : public Command
{
public:
    OrgCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~OrgCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ORGCOMMAND_H
