#include <iostream>
#include <vector>
#include <deque>
#include <concepts>
#include "StaticLibPrivate.hpp"

namespace Code::StaticLib
{

void InvokeLambdaCpp20Style()
{
    std::deque dequeInt {6, 5, 4, 3, 2, 1};
    std::vector vectorInt {1, 2, 3, 4, 5};
    std::vector vectorDouble {1.1, 2.2, 3.3, 4.4};

    auto lambdaAnyArgWithSize = [](const auto& arg) { return arg.size(); };
    auto lambdaVectorAny = []<typename T>(const std::vector<T>& vec) { return vec.size(); };
    auto lambdaVectorInt = []<std::integral T>(const std::vector<T>& vec) { return vec.size(); };

    std::cout << "Code::StaticLib::InvokeLambdaCpp20Style: " 
        << lambdaAnyArgWithSize(dequeInt) << "\t"
        << lambdaAnyArgWithSize(vectorDouble) << "\t"
        << lambdaVectorAny(vectorInt) << "\t"
        << lambdaVectorAny(vectorDouble) << "\t"
        << lambdaVectorInt(vectorInt) << "\n";
}
    
} // ~namespace Code::StaticLib
