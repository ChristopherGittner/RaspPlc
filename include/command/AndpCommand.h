#ifndef ANDPCOMMAND_H
#define ANDPCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class AndpCommand : public Command
{
public:
    AndpCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device),
        mOldState(false)
    {}

    virtual ~AndpCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
    bool mOldState;
};

#endif // ANDPCOMMAND_H
