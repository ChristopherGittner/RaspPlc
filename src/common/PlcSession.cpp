#include "common/PlcSession.h"

#include <iostream>
#include <assert.h>
#include <fstream>

#include <boost/bind.hpp>

#include "common/RaspPlc.h"

void PlcSession::start()
{
    uint32_t* len = new uint32_t();

    async_read(mSocket, buffer(len, sizeof(len)), boost::bind(&PlcSession::handleReadLen, this, len, placeholders::error));
}

void PlcSession::handleReadLen(uint32_t* len, const boost::system::error_code& ec)
{
    if(!ec)
    {
        char* data = new char[*len];
        async_read(mSocket, buffer(data, *len), boost::bind(&PlcSession::handleReadData, this, len, data, placeholders::error));
    }
    else
    {
        std::cout << "Error while reading length: " << ec.message() << std::endl;
        delete len;
    }
}

void PlcSession::handleReadData(uint32_t* len, char* data, const boost::system::error_code& ec)
{
    if(!ec)
    {
        std::cout << "Received: " << data << std::endl;
        std::ofstream ofs("program.prg");
        assert(ofs.good());

        ofs << data;
    }
    else
    {
        std::cout << "Error while reading data: " << ec.message() << std::endl;
    }

    delete len;
    delete[] data;

    mPlc.requestReloadProgram();

    unsigned int* answer = new unsigned int();
    *answer = 0;

    async_write(mSocket, buffer(answer, sizeof(unsigned int)), boost::bind(&PlcSession::handleWriteAnswer, this, answer, placeholders::error));
}

void PlcSession::handleWriteAnswer(unsigned int* answer, const boost::system::error_code& ec)
{
    if(!ec)
    {

    }
    else
    {
        std::cout << "Error while writing answer: " << ec.message() << std::endl;
    }

    delete answer;
}
