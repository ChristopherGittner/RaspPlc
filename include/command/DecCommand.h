#ifndef DECCOMMAND_H
#define DECCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class DecCommand : public Command
{
public:
    DecCommand(std::shared_ptr<DWordDevice> device) :
        Command(),
        mDevice(device)
    {}

    virtual ~DecCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mDevice;
};

#endif // DECCOMMAND_H
