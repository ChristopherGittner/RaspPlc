#ifndef EGPCOMMAND_H
#define EGPCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class EgpCommand : public Command
{
public:
    EgpCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device),
        mOldState(false)
    {}

    virtual ~EgpCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
    bool mOldState;
};

#endif // EGPCOMMAND_H
