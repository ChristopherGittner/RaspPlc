#ifndef ANICOMMAND_H
#define ANICOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class AniCommand : public Command
{
public:
    AniCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device)
    {}

    virtual ~AniCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
};

#endif // ANICOMMAND_H
