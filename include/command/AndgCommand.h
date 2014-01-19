#ifndef ANDGCOMMAND_H
#define ANDGCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class AndgCommand : public Command
{
public:
    AndgCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~AndgCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ANDGCOMMAND_H
