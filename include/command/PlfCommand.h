#ifndef PLFCOMMAND_H
#define PLFCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class PlfCommand : public Command
{
public:
    PlfCommand(std::shared_ptr<BitDevice> device) :
        Command(),
        mOldState(false),
        mDevice(device)
    {}

    virtual ~PlfCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;


protected:

private:
    bool mOldState;

    std::shared_ptr<BitDevice> mDevice;
};

#endif // PLFCOMMAND_H
