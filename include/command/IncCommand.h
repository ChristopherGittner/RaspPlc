#ifndef INCCOMMAND_H
#define INCCOMMAND_H

#include "command/Command.h"

#include <memory>

class DWordDevice;

class IncCommand : public Command
{
public:
    IncCommand(std::shared_ptr<DWordDevice> device) :
        Command(),
        mDevice(device)
    {}

    virtual ~IncCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

    std::shared_ptr<DWordDevice> mDevice;
};

#endif // INCCOMMAND_H
