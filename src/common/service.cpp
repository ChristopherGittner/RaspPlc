#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <memory>
#include <fstream>
#include <string>
#include <sstream>

#include "common/RaspPlc.h"
#include "parser/ConfigParser.h"
#include "common/Program.h"
#include "parser/StlParser.h"

int main(int argc, char** argv)
{
    RaspPlc* plc;
    {
        std::ifstream ifs("config.conf");
        assert(ifs.good());

        plc = ConfigParser::getInstance().parsePlc(ifs);
    }

    while(true)
    {
        try
        {
            std::cout << "Start of Loop" << std::endl;
            plc->run();
            usleep(1000000);
        }
        catch (std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        usleep(1000000);
    }

    return EXIT_SUCCESS;
}
