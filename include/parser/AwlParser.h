#ifndef AWLPARSER_H
#define AWLPARSER_H

#include <sstream>
#include <memory>

class RaspPlc;
class Program;

class AwlParser
{
public:
    static AwlParser& getInstance();

    std::shared_ptr<Program> parse(std::istream& is, const RaspPlc& plc);
protected:

private:
    AwlParser() {}
    AwlParser(const AwlParser&);
};

#endif // AWLPARSER_H
