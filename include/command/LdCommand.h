#ifndef LDCOMMAND_H
#define LDCOMMAND_H

#include "command/Command.h"

#include <memory>
#include <iostream>

class BitDevice;

class LdCommand : public Command
{
public:
    LdCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device)
    {}

    virtual ~LdCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
};

#endif // LDCOMMAND_H
