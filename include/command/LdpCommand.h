#ifndef LDPCOMMAND_H
#define LDPCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class LdpCommand : public Command
{
public:
    LdpCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device),
        mOldState(false)
    {}

    virtual ~LdpCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
    bool mOldState;
};

#endif // LDPCOMMAND_H
