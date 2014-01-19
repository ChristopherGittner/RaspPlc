#ifndef PLCSERVER_H
#define PLCSERVER_H

#include <boost/asio.hpp>
using namespace boost::asio;

class RaspPlc;
class PlcSession;

class PlcServer
{
public:
    PlcServer(io_service& service, const ip::tcp::endpoint& endpoint, RaspPlc& plc);

    virtual ~PlcServer() {}

protected:

private:

    void startAccept();
    void handleAccept(PlcSession* session, const boost::system::error_code& ec);

    io_service& mService;
    ip::tcp::acceptor mAcceptor;

    RaspPlc& mPlc;
};

#endif // PLCSERVER_H
