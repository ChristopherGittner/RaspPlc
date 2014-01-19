#ifndef MOVPCOMMAND_H
#define MOVPCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class MovpCommand : public Command
{
public:
    MovpCommand(std::shared_ptr<DWordDevice> leftDevice, std::shared_ptr<DWordDevice> rightDevice) :
        Command(),
        mOldState(false),
        mLeftDevice(leftDevice),
        mRightDevice(rightDevice)
    {}

    virtual ~MovpCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    bool mOldState;

    std::shared_ptr<DWordDevice> mLeftDevice;
    std::shared_ptr<DWordDevice> mRightDevice;
};

#endif // MOVPCOMMAND_H
