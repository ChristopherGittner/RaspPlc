#ifndef PLCSESSION_H
#define PLCSESSION_H

#include <memory>

#include <boost/asio.hpp>
using namespace boost::asio;

class RaspPlc;

class PlcSession
{
public:
    PlcSession(io_service& service, RaspPlc& plc) :
        mService(service),
        mSocket(service),
        mPlc(plc)
    {}

    virtual ~PlcSession() {}

    ip::tcp::socket& socket()
    {
        return mSocket;
    }

    void start();

protected:

private:

    void handleReadLen(uint32_t* len, const boost::system::error_code& ec);
    void handleReadData(uint32_t* len, char* data, const boost::system::error_code& ec);
    void handleWriteAnswer(unsigned int* answer, const boost::system::error_code& ec);

    io_service& mService;
    ip::tcp::socket mSocket;

    RaspPlc& mPlc;
};

#endif // PLCSESSION_H
