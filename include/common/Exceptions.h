#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class NoSuchDeviceException : public std::exception
{
public:
    NoSuchDeviceException(const std::string& msg) :
        exception(),
        mMsg("No Such Device: " + msg)
    {}
    virtual ~NoSuchDeviceException() noexcept {}

    virtual const char* what() const throw() override
    {
        return mMsg.c_str();
    }

protected:

private:

    std::string mMsg;
};

class FailedToParseException : public std::exception
{
public:
    FailedToParseException(const std::string& msg) :
        exception(),
        mMsg("Failed to parse: " + msg)
    {}
    virtual ~FailedToParseException() noexcept {}

    virtual const char* what() const throw() override
    {
        return mMsg.c_str();
    }

protected:

private:

    std::string mMsg;
};

class InvalidArgumentException : public std::exception
{
public:
    InvalidArgumentException(const std::string& msg) :
        exception(),
        mMsg("Invalid Argument: " + msg)
    {}
    virtual ~InvalidArgumentException() noexcept {}

    virtual const char* what() const throw() override
    {
        return mMsg.c_str();
    }

protected:

private:

    std::string mMsg;
};

class ModbusException : public std::exception
{
public:
    ModbusException(const std::string& msg) :
        exception(),
        mMsg("Modbus Exception: " + msg)
    {}
    virtual ~ModbusException() noexcept {}

    virtual const char* what() const throw() override
    {
        return mMsg.c_str();
    }

protected:

private:

    std::string mMsg;
};

class DeviceCannotBeSetException : public std::exception
{
public:
    DeviceCannotBeSetException(const std::string& msg) :
        exception(),
        mMsg("Device can not be set Exception: " + msg)
    {}
    virtual ~DeviceCannotBeSetException() noexcept {}

    virtual const char* what() const throw() override
    {
        return mMsg.c_str();
    }

protected:

private:

    std::string mMsg;
};
#endif // EXCEPTIONS_H
