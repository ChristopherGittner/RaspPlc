#include "parser/ConfigParser.h"

#include <string>

#include <boost/lexical_cast.hpp>

#include "module/InputModule.h"
#include "module/OutputModule.h"
#include "module/PifaceModule.h"
#include "common/RaspPlc.h"
#include "common/Exceptions.h"

ConfigParser& ConfigParser::getInstance()
{
    static ConfigParser instance;
    return instance;
}

RaspPlc* ConfigParser::parsePlc(std::istream& is)
{
    std::string token;

    while(is >> token)
    {
        std::transform(token.begin(), token.end(), token.begin(), tolower);
        if(token == "raspplc")
        {
            std::string inputs, outputs, flags, dataRegisters, timers;

            is >> inputs >> outputs >> flags >> dataRegisters >> timers;

            return new RaspPlc(boost::lexical_cast<size_t>(inputs),
                               boost::lexical_cast<size_t>(outputs),
                               boost::lexical_cast<size_t>(flags),
                               boost::lexical_cast<size_t>(dataRegisters),
                               boost::lexical_cast<size_t>(timers));
        }
    }
    throw FailedToParseException("No raspplc entry found");
}

std::vector<std::shared_ptr<PifaceModule>> ConfigParser::parsePifaceModules(std::istream& is, RaspPlc& plc)
{
    std::vector<std::shared_ptr<PifaceModule>> modules;

    std::string token;

    while(is >> token)
    {
        std::transform(token.begin(), token.end(), token.begin(), tolower);
        if(token == "piface")
        {
            std::string startInputDevice, startOutputDevice, address;
            is >> startInputDevice >> startOutputDevice >> address;

            modules.push_back(std::make_shared<PifaceModule>(plc.findDWordDeviceByName(startInputDevice), plc.findDWordDeviceByName(startOutputDevice), boost::lexical_cast<unsigned int>(address)));
        }
    }

    return modules;
}
