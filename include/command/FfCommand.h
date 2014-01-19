#ifndef FFCOMMAND_H
#define FFCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class FfCommand : public Command
{
public:
    FfCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device),
        mOldState(false)
    {}

    virtual ~FfCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
    bool mOldState;
};

#endif // FFCOMMAND_H
