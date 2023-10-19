#include <iostream>
#include <map>
#include <tuple>
#include "SharedOrStaticLibPrivate.hpp"

namespace Code::SharedOrStaticLib
{

namespace A::B::C
{
    class Dummy final {};
    
    auto ReturnTuple()
    {
        Dummy dummy;
        std::map<int, double> myMap { {1, 1.1}, {2, 2.2}, {3, 3.3} };

        return std::tuple('a', false, -4, -5.5, dummy, myMap);
    }
}

void AutoReturnStructuredBindingsCpp17()
{
    std::cout << "Code::SharedOrStaticLib::AutoReturnStructuredBindingsCpp17\n";

    auto [x1, x2, x3, x4, x5, x6] = A::B::C::ReturnTuple();

    for (const auto& [key, value] : x6)
    {
        std::cout << "key = " << key << ", value = " << value << "\n";
    }
}

} // ~namespace Code::SharedOrStaticLib
