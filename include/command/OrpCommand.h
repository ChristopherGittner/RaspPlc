#ifndef ORPCOMMAND_H
#define ORPCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class OrpCommand : public Command
{
public:
    OrpCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device),
        mOldState(false)
    {}

    virtual ~OrpCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
    bool mOldState;
};

#endif // ORPCOMMAND_H
