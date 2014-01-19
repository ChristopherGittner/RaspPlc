#ifndef LDGCOMMAND_H
#define LDGCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class LdgCommand : public Command
{
public:
    LdgCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~LdgCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // LDGCOMMAND_H
