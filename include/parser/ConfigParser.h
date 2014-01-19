#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <memory>
#include <vector>
#include <sstream>

class RaspPlc;
class PifaceModule;

class ConfigParser
{
public:
    static ConfigParser& getInstance();

    RaspPlc* parsePlc(std::istream& is);
    std::vector<std::shared_ptr<PifaceModule>> parsePifaceModules(std::istream& is, RaspPlc& plc);

protected:

private:
    ConfigParser() {}
    ConfigParser(const ConfigParser&);
};

#endif // CONFIGPARSER_H
