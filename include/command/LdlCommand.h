#ifndef LDLCOMMAND_H
#define LDLCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class LdlCommand : public Command
{
public:
    LdlCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~LdlCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // LDLCOMMAND_H
