#ifndef ORBCOMMAND_H
#define ORBCOMMAND_H

#include "command/Command.h"

class OrbCommand : public Command
{
public:
    OrbCommand() {}

    virtual ~OrbCommand() {};

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

};

#endif // ORBCOMMAND_H
