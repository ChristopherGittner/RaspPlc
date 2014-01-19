#ifndef ANDECOMMAND_H
#define ANDECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class AndeCommand : public Command
{
public:
    AndeCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~AndeCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ANDECOMMAND_H
