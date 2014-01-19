#ifndef LDECOMMAND_H
#define LDECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class LdeCommand : public Command
{
public:
    LdeCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~LdeCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // LDECOMMAND_H
