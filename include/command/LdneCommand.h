#ifndef LDNECOMMAND_H
#define LDNECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class LdneCommand : public Command
{
public:
    LdneCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~LdneCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // LDNECOMMAND_H
