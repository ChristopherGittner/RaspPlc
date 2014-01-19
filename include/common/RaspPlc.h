#ifndef RASPPLC_H
#define RASPPLC_H

#include <string>
#include <vector>
#include <memory>
#include <thread>

#include <boost/asio.hpp>
using namespace boost::asio;

#include "common/PlcServer.h"

class BitDevice;
class Program;
class Input;
class Output;
class Flag;
class SpecialFlag;
class InputModule;
class OutputModule;
class DataRegister;
class SpecialDataRegister;
class DWordDevice;
class Timer;

class RaspPlc
{
public:
    RaspPlc(size_t nInputs, size_t nOutputs, size_t nFlags, size_t nDataRegisters, size_t nTimers);
    void run();
    void execute();
    void requestReloadProgram();

    virtual ~RaspPlc() {}

    std::shared_ptr<BitDevice> findBitDeviceByName(std::string name) const;
    std::shared_ptr<DWordDevice> findDWordDeviceByName(std::string name) const;
    std::shared_ptr<Timer> findTimerByName(std::string name) const;

    void setInputModules(std::vector<std::shared_ptr<InputModule>> modules)
    {
        mInputModules = modules;
    }
    const std::vector<std::shared_ptr<InputModule>>& getInputModules()
    {
        return mInputModules;
    }

    void setOutputModules(std::vector<std::shared_ptr<OutputModule>> modules)
    {
        mOutputModules = modules;
    }
    const std::vector<std::shared_ptr<OutputModule>>& getOutputModules()
    {
        return mOutputModules;
    }

protected:

private:

    void initTimers();
    void reloadProgram();
    void readInputs();
    void prepareSpecialFlags();
    void prepareSpecialDataRegisters();
    void writeOutputs();

    virtual std::shared_ptr<BitDevice> findInputByName(const std::string& name) const;
    virtual std::shared_ptr<BitDevice> findOutputByName(const std::string& name) const;
    virtual std::shared_ptr<BitDevice> findFlagByName(const std::string& name) const;
    virtual std::shared_ptr<BitDevice> findSpecialFlagByName(const std::string& name) const;
    virtual std::shared_ptr<DWordDevice> findDataRegisterByName(const std::string& name) const;
    virtual std::shared_ptr<DWordDevice> findSpecialDataRegisterByName(const std::string& name) const;

    std::thread* mNetworkThread;
    std::thread* mPlcThread;

    io_service mService;
    PlcServer mServer;

    std::shared_ptr<Program> mProgram;

    std::vector<std::shared_ptr<InputModule>> mInputModules;
    std::vector<std::shared_ptr<OutputModule>> mOutputModules;

    std::vector<std::shared_ptr<Input>> mInputs;
    std::vector<std::shared_ptr<Output>> mOutputs;
    std::vector<std::shared_ptr<Flag>> mFlags;
    std::vector<std::shared_ptr<SpecialFlag>> mSpecialFlags;
    std::vector<std::shared_ptr<DataRegister>> mDataRegisters;
    std::vector<std::shared_ptr<SpecialDataRegister>> mSpecialDataRegisters;
    std::vector<std::shared_ptr<Timer>> mTimers;

    std::chrono::high_resolution_clock::time_point mTimepointStart;
    std::chrono::high_resolution_clock::time_point mTimepointCurrentCycle;

    volatile bool mReloadProgram;
    volatile bool mProgramReloaded;
};

#endif // RASPPLC_H
