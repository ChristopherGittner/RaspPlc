#ifndef ANDLCOMMAND_H
#define ANDLCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class AndlCommand : public Command
{
public:
    AndlCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~AndlCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ANDLCOMMAND_H
