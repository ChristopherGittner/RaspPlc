#ifndef CONSTANTDWORD_H
#define CONSTANTDWORD_H

#include "device/DWordDevice.h"

#include <string>

#include <boost/lexical_cast.hpp>

#include "common/Types.h"

class ConstantDWord : public DWordDevice
{
public:
    ConstantDWord(const dword value) :
        DWordDevice("k" + boost::lexical_cast<std::string>(value)),
        mValue(value)
    {}

    virtual ~ConstantDWord() {}

    virtual dword getValue() const override;

    virtual void setValue(dword value) override;

protected:

private:

    const dword mValue;
};

#endif // CONSTANTDWORD_H
