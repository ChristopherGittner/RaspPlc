#ifndef LDICOMMAND_H
#define LDICOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class LdiCommand : public Command
{
public:
    LdiCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device)
    {}

    virtual ~LdiCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
};

#endif // LDICOMMAND_H
