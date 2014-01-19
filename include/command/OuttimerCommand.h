#ifndef OUTTIMERCOMMAND_H
#define OUTTIMERCOMMAND_H

#include "command/Command.h"

#include <memory>

class Timer;
class DWordDevice;

class OuttimerCommand : public Command
{
public:
    OuttimerCommand(std::shared_ptr<Timer> device, std::shared_ptr<DWordDevice> durationDevice) :
        mDevice(device),
        mDurationDevice(durationDevice),
        mOldState(false)
    {}

    virtual ~OuttimerCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<Timer> mDevice;
    std::shared_ptr<DWordDevice> mDurationDevice;

    bool mOldState;
};

#endif // OUTTIMERCOMMAND_H
