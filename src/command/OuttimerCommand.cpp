#include "command/OuttimerCommand.h"

#include "command/CommandExecutionContext.h"
#include "device/BitDevice.h"
#include "device/Timer.h"

#include <iostream>

void OuttimerCommand::execute(CommandExecutionContext& context)
{
    mDevice->setCurrentTime(context.CurrentTime);
    mDevice->setDuration(std::chrono::milliseconds(mDurationDevice->getValue()));

    if(!context.Rlo || (context.Rlo && !mOldState))
        mDevice->setValue(0);

    if(mDevice->getValue() > mDurationDevice->getValue())
        mDevice->setValue(mDurationDevice->getValue());

    mOldState = context.Rlo;
}

std::string OuttimerCommand::print()
{
    return "OUT " + mDevice->print() + " " + mDurationDevice->print();
}
