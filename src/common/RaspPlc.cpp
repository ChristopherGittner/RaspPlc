#include "common/RaspPlc.h"

#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>

#include "common/Exceptions.h"
#include "device/ConstantDWord.h"
#include "device/GroupedBitDevice.h"
#include "command/CommandExecutionContext.h"
#include "common/Program.h"
#include "command/Command.h"
#include "parser/StlParser.h"
#include "parser/ConfigParser.h"
#include "module/PifaceModule.h"
#include "module/InputModule.h"
#include "module/OutputModule.h"
#include "device/Input.h"
#include "device/Output.h"
#include "device/Flag.h"
#include "device/SpecialFlag.h"
#include "device/DataRegister.h"
#include "device/SpecialDataRegister.h"
#include "device/Timer.h"

RaspPlc::RaspPlc(size_t nInputs, size_t nOutputs, size_t nFlags, size_t nDataRegisters, size_t nTimers) :
    mNetworkThread(nullptr),
    mPlcThread(nullptr),
    mService(),
    mServer(mService, ip::tcp::endpoint(ip::tcp::v4(), 8888), *this),
    mProgram(nullptr),
    mInputModules(),
    mOutputModules(),
    mInputs(),
    mOutputs(),
    mFlags(),
    mSpecialFlags(),
    mDataRegisters(),
    mSpecialDataRegisters(),
    mTimepointStart(),
    mTimepointCurrentCycle(),
    mReloadProgram(false),
    mProgramReloaded(false)
{
    for(size_t i = 0; i != nInputs; ++i)
    {
        std::ostringstream oss;
        oss << std::hex << i;

        mInputs.emplace_back(new Input(oss.str()));
    }
    for(size_t i = 0; i != nOutputs; ++i)
    {
        std::ostringstream oss;
        oss << std::hex << i;

        mOutputs.emplace_back(new Output(oss.str()));
    }
    for(size_t i = 0; i != nFlags; ++i)
    {
        std::ostringstream oss;
        oss << std::hex << i;

        mFlags.emplace_back(new Flag(oss.str()));
    }
    for(size_t i = 0; i != 0xff; ++i)
    {
        std::ostringstream oss;
        oss << std::hex << i;

        mSpecialFlags.emplace_back(new SpecialFlag(oss.str()));
    }
    for(size_t i = 0; i != nDataRegisters; ++i)
    {
        std::ostringstream oss;
        oss << std::hex << i;

        mDataRegisters.emplace_back(new DataRegister(oss.str()));
    }
    for(size_t i = 0; i != 0xff; ++i)
    {
        std::ostringstream oss;
        oss << std::hex << i;

        mSpecialDataRegisters.emplace_back(new SpecialDataRegister(oss.str()));
    }
    for(size_t i = 0; i != nTimers; ++i)
    {
        std::ostringstream oss;
        oss << std::hex << i;

        mTimers.emplace_back(new Timer(oss.str()));
    }

    try
    {

        std::ifstream ifs("config.conf");
        assert(ifs.good());

        std::vector<std::shared_ptr<PifaceModule>> modules(ConfigParser::getInstance().parsePifaceModules(ifs, *this));

        for(auto module : modules)
            mInputModules.push_back(module);

        for(auto module : modules)
            mOutputModules.push_back(module);
    }
    catch(std::exception& e)
    {
        std::cout << "Failed to load Config: " << e.what() << std::endl;
    }
    try
    {
        std::ifstream ifs("program.prg");
        assert(ifs.good());

        mProgram = StlParser::getInstance().parse(ifs, *this);
    }
    catch(std::exception& e)
    {
        std::cout << "Failed to load Program: " << e.what() << std::endl;
    }

    mNetworkThread = new std::thread([this]()
    {
        mService.run();
    });
}

std::shared_ptr<BitDevice> RaspPlc::findBitDeviceByName(std::string name) const
{
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    if(name[0] == 'x')
    {
        return findInputByName(name);
    }
    else if(name[0] == 'y')
    {
        return findOutputByName(name);
    }
    else if(name[0] == 'm')
    {
        return findFlagByName(name);
    }
    else if(name[0] == 's' && name[1] == 'm')
    {
        return findSpecialFlagByName(name);
    }
    else if(name[0] == 't')
    {
        return findTimerByName(name);
    }

    throw NoSuchDeviceException(name);
}

std::shared_ptr<DWordDevice> RaspPlc::findDWordDeviceByName(std::string name) const
{
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    if(name[0] == 'd')
    {
        return findDataRegisterByName(name);
    }
    if(name[0] == 's' && name[1] == 'd')
    {
        return findSpecialDataRegisterByName(name);
    }
    else if(name[0] == 'k')
    {
        return std::make_shared<ConstantDWord>(boost::lexical_cast<dword>(name.substr(1)));
    }
    else if(name[0] == 'x' || name[0] == 'y' || name[0] == 'm')
    {
        std::vector<std::shared_ptr<BitDevice>> devices;

        std::istringstream iss(name);
        std::string token;
        while(std::getline(iss, token, ';'))
        {
            devices.push_back(findBitDeviceByName(token));
        }

        return std::make_shared<GroupedBitDevice>(devices);
    }
    else if(name[0] == 't')
    {
        return findTimerByName(name);
    }

    throw NoSuchDeviceException(name);
}

std::shared_ptr<Timer> RaspPlc::findTimerByName(std::string name) const
{
    std::transform(name.begin(), name.end(), name.begin(), tolower);

    for(auto timer : mTimers)
    {
        if(timer->getName() == name)
            return timer;
    }

    throw NoSuchDeviceException(name);
}

std::shared_ptr<BitDevice> RaspPlc::findInputByName(const std::string& name) const
{
    for(auto input : mInputs)
    {
        if(input->getName() == name)
            return input;
    }

    throw NoSuchDeviceException(name);
}

std::shared_ptr<BitDevice> RaspPlc::findOutputByName(const std::string& name) const
{
    for(auto output : mOutputs)
    {
        if(output->getName() == name)
            return output;
    }

    throw NoSuchDeviceException(name);
}

std::shared_ptr<BitDevice> RaspPlc::findFlagByName(const std::string& name) const
{
    for(auto flag : mFlags)
    {
        if(flag->getName() == name)
            return flag;
    }

    throw NoSuchDeviceException(name);
}

std::shared_ptr<BitDevice> RaspPlc::findSpecialFlagByName(const std::string& name) const
{
    for(auto specialFlag : mSpecialFlags)
    {
        if(specialFlag->getName() == name)
            return specialFlag;
    }

    throw NoSuchDeviceException(name);
}

std::shared_ptr<DWordDevice> RaspPlc::findDataRegisterByName(const std::string& name) const
{
    for(auto reg : mDataRegisters)
    {
        if(reg->getName() == name)
            return reg;
    }

    throw NoSuchDeviceException(name);
}

std::shared_ptr<DWordDevice> RaspPlc::findSpecialDataRegisterByName(const std::string& name) const
{
    for(auto reg : mSpecialDataRegisters)
    {
        if(reg->getName() == name)
            return reg;
    }

    throw NoSuchDeviceException(name);
}

void RaspPlc::run()
{
    mTimepointStart = std::chrono::high_resolution_clock::now();

    initTimers();

    while(true)
    {
        mTimepointCurrentCycle = std::chrono::high_resolution_clock::now();

        if(mReloadProgram)
            reloadProgram();

        readInputs();
        prepareSpecialFlags();
        prepareSpecialDataRegisters();
        execute();
        writeOutputs();
        //auto end = std::chrono::high_resolution_clock::now();
        //auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    }
}

void RaspPlc::execute()
{
    CommandExecutionContext context;

    context.Rlo = true;
    context.RloStack.clear();
    context.CurrentTime = mTimepointCurrentCycle;

    if(!mProgram)
        return;

    auto commands = mProgram->getCommands();

    for(auto command : commands)
    {
        command->execute(context);
    }
}

void RaspPlc::requestReloadProgram()
{
    mReloadProgram = true;
    while(!mProgramReloaded);
    mProgramReloaded = false;
}

void RaspPlc::initTimers()
{

}

void RaspPlc::reloadProgram()
{
    std::cout << "reloadProgram()" << std::endl;
    std::ifstream ifs("program.prg");
    assert(ifs.good());

    try
    {
        mProgram = StlParser::getInstance().parse(ifs, *this);
    }
    catch(std::exception& e)
    {
        std::cout << "Failed to load Program: " << e.what() << std::endl;
    }

    mReloadProgram = false;
    mProgramReloaded = true;
    while(mProgramReloaded);
}

void RaspPlc::readInputs()
{
    for(auto module : mInputModules)
        module->readFromModule();
}

void RaspPlc::prepareSpecialFlags()
{
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(mTimepointCurrentCycle - mTimepointStart).count();

    findSpecialFlagByName("sm0")->setState(false);
    findSpecialFlagByName("sm1")->setState(true);
    findSpecialFlagByName("sm10")->setState((ms % 100) >= 50);
    findSpecialFlagByName("sm11")->setState((ms % 200) >= 100);
    findSpecialFlagByName("sm12")->setState((ms % 1000) >= 500);
    findSpecialFlagByName("sm13")->setState((ms % 2000) >= 1000);
}

void RaspPlc::prepareSpecialDataRegisters()
{
    auto now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);

    tm localTime = *localtime(&tt);

    findSpecialDataRegisterByName("sd10")->setValue(localTime.tm_year + 1970);
    findSpecialDataRegisterByName("sd11")->setValue(localTime.tm_mon + 1);
    findSpecialDataRegisterByName("sd12")->setValue(localTime.tm_mday);
    findSpecialDataRegisterByName("sd13")->setValue(localTime.tm_hour);
    findSpecialDataRegisterByName("sd14")->setValue(localTime.tm_min);
    findSpecialDataRegisterByName("sd15")->setValue(localTime.tm_sec);
    findSpecialDataRegisterByName("sd16")->setValue(localTime.tm_yday);
    findSpecialDataRegisterByName("sd17")->setValue(localTime.tm_wday);
}

void RaspPlc::writeOutputs()
{
    for(auto module : mOutputModules)
        module->writeToModule();
}
