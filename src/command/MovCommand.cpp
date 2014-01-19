#include "command/MovCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/DWordDevice.h"

void MovCommand::execute(CommandExecutionContext& context)
{
    if(context.Rlo)
        mRightDevice->setValue(mLeftDevice->getValue());
}

std::string MovCommand::print()
{
    return "MOV " + mLeftDevice->print() + " " + mRightDevice->print();
}
