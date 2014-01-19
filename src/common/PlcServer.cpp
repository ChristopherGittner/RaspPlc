#include "common/PlcServer.h"

#include <boost/bind.hpp>

#include "common/PlcSession.h"

PlcServer::PlcServer(io_service& service, const ip::tcp::endpoint& endpoint, RaspPlc& plc) :
    mService(service),
    mAcceptor(mService, endpoint),
    mPlc(plc)
{
    startAccept();
}

void PlcServer::startAccept()
{
    PlcSession* session = new PlcSession(mService, mPlc);

    mAcceptor.async_accept(session->socket(), boost::bind(&PlcServer::handleAccept, this, session, placeholders::error));
}

void PlcServer::handleAccept(PlcSession* session, const boost::system::error_code& ec)
{
    if(!ec)
    {
        session->start();
    }
    else
    {
        delete session;
    }
    startAccept();
}
