#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device
{
public:
    Device(const std::string& name) :
        mName(name)
    {}

    virtual ~Device() {}

    virtual std::string getName() const
    {
        return mName;
    }

    virtual std::string print() const;

protected:

private:
    std::string mName;
};

#endif // DEVICE_H
