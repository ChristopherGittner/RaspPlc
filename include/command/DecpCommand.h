#ifndef DECPCOMMAND_H
#define DECPCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class DecpCommand : public Command
{
public:
    DecpCommand(std::shared_ptr<DWordDevice> device) :
        Command(),
        mOldState(false),
        mDevice(device)
    {}

    virtual ~DecpCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    bool mOldState;

    std::shared_ptr<DWordDevice> mDevice;
};

#endif // DECPCOMMAND_H
