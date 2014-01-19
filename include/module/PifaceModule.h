#ifndef PIFACEMODULE_H
#define PIFACEMODULE_H

#include "module/InputModule.h"
#include "module/OutputModule.h"

#include <memory>

class DWordDevice;

class PifaceModule : public InputModule, public OutputModule
{
public:
    PifaceModule(std::shared_ptr<DWordDevice> inDevice, std::shared_ptr<DWordDevice> outDevice, const unsigned int address) :
        InputModule(inDevice),
        OutputModule(outDevice),
        mAddress(address),
        mIsOpen(false)
    {}

    virtual ~PifaceModule();

    virtual void readFromModule() override;
    virtual void writeToModule() override;

protected:

private:

    void open();
    void close();

    const unsigned int mAddress;
    bool mIsOpen;
};

#endif // PIFACEMODULE_H
