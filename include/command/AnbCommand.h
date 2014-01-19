#ifndef ANBCOMMAND_H
#define ANBCOMMAND_H

#include "command/Command.h"

class AnbCommand : public Command
{
public:
    AnbCommand() {}

    virtual ~AnbCommand() {}

    virtual void execute(CommandExecutionContext& context) override;
    virtual std::string print() override;

protected:

private:

};

#endif // ANBCOMMAND_H
