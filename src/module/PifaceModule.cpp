#include "module/PifaceModule.h"

#include <iostream>
#include <string>

#include <boost/lexical_cast.hpp>

#include "external/pifacedigital.h"
#include "device/DWordDevice.h"

PifaceModule::~PifaceModule()
{
    if(mIsOpen)
        close();
}

void PifaceModule::open()
{
#ifdef __arm__
    pifacedigital_open(mAddress);
#endif

    mIsOpen = true;
}

void PifaceModule::close()
{
#ifdef __arm__
    pifacedigital_close(mAddress);
#endif
}

void PifaceModule::readFromModule()
{
    if(!mIsOpen)
        open();

#ifdef __arm__
    uint8_t input = pifacedigital_read_reg(INPUT, mAddress);
#else
    std::cout << "input = pifacedigital_read_reg(INPUT, mAddress)" << std::endl;
    std::string s;
    std::cin >> s;
    uint8_t input = boost::lexical_cast<unsigned int>(s);
#endif

    mInDevice->setValue(input);
}

void PifaceModule::writeToModule()
{
    if(!mIsOpen)
        open();

#ifdef __arm__
    pifacedigital_write_reg(mOutDevice->getValue(), OUTPUT, mAddress);
#endif
}
