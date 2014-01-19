#ifndef SIMULATIONCONTEXT_H
#define SIMULATIONCONTEXT_H

#include <vector>
#include <chrono>

struct CommandExecutionContext
{
    bool Rlo;

    std::vector<bool> RloStack;

    std::chrono::high_resolution_clock::time_point CurrentTime;
};

#endif // SIMULATIONCONTEXT_H
