#include <iostream>
#include "SharedLibPrivate.hpp"

namespace Code::SharedLib
{

struct Machine
{
    int cogwheels {0};

    auto GetLambdaCaptureCopyOfMachine()
    {
        return [*this](){ return cogwheels; };
    }
};

void InvokeLambdaCpp17Style()
{
    auto lambda = Machine{4}.GetLambdaCaptureCopyOfMachine();
    double outliveMachine = lambda();
    std::cout << "Code::SharedLib::InvokeLambdaCpp17Style: " << outliveMachine << "\n";
}

} // ~namespace Code::SharedLib
