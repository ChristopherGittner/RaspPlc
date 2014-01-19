#ifndef LDGECOMMAND_H
#define LDGECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class LdgeCommand : public Command
{
public:
    LdgeCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~LdgeCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // LDGECOMMAND_H
