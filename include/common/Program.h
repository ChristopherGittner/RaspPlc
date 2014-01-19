#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <string>
#include <memory>

class Command;

class Program
{
public:
    Program(const std::vector<std::shared_ptr<Command>>& commands) :
        mCommands(commands)
    {}

    virtual ~Program() {}

    std::string print();

    const std::vector<std::shared_ptr<Command>>& getCommands()
    {
        return mCommands;
    }

protected:

private:
    std::vector<std::shared_ptr<Command>> mCommands;
};

#endif // PROGRAM_H
