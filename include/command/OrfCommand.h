#ifndef ORFCOMMAND_H
#define ORFCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class OrfCommand : public Command
{
public:
    OrfCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device),
        mOldState(false)
    {}

    virtual ~OrfCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
    bool mOldState;
};

#endif // ORFCOMMAND_H
