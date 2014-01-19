#ifndef EGFCOMMAND_H
#define EGFCOMMAND_H

#include "command/Command.h"

#include <memory>

class BitDevice;

class EgfCommand : public Command
{
public:
    EgfCommand(std::shared_ptr<BitDevice> device) :
        mDevice(device),
        mOldState(false)
    {}

    virtual ~EgfCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:
    std::shared_ptr<BitDevice> mDevice;
    bool mOldState;
};

#endif // EGFCOMMAND_H
