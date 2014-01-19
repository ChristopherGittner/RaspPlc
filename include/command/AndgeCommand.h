#ifndef ANDGECOMMAND_H
#define ANDGECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class AndgeCommand : public Command
{
public:
    AndgeCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~AndgeCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ANDGECOMMAND_H
