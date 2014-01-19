#ifndef ORECOMMAND_H
#define ORECOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class OreCommand : public Command
{
public:
    OreCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~OreCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // ORECOMMAND_H
