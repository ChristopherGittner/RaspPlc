#ifndef OUTPUTMODULE_H
#define OUTPUTMODULE_H

#include <memory>

class DWordDevice;

class OutputModule
{
public:
    OutputModule(std::shared_ptr<DWordDevice> outDevice) :
        mOutDevice(outDevice)
    {}

    virtual ~OutputModule() {}

    std::shared_ptr<DWordDevice> getOutDevice()
    {
        return mOutDevice;
    }

    virtual void writeToModule() = 0;

protected:
    std::shared_ptr<DWordDevice> mOutDevice;

private:
};

#endif // OUTPUTMODULE_H
