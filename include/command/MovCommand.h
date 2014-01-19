#ifndef MOVCOMMAND_H
#define MOVCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class MovCommand : public Command
{
public:
    MovCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~MovCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // MOVCOMMAND_H
