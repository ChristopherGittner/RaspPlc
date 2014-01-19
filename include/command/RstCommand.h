#ifndef RSTCOMMAND_H
#define RSTCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class RstCommand : public Command
{
public:
    RstCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device)
    {}

    virtual ~RstCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;


protected:

private:
    std::shared_ptr<BitDevice> mDevice;
};

#endif // RSTCOMMAND_H
