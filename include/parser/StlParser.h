#ifndef StlPARSER_H
#define StlPARSER_H

#include <sstream>
#include <memory>

class RaspPlc;
class Program;

class StlParser
{
public:
    static StlParser& getInstance();

    std::shared_ptr<Program> parse(std::istream& is, const RaspPlc& plc);
protected:

private:
    StlParser() {}
    StlParser(const StlParser&);
};

#endif // StlPARSER_H
