#include <iostream>
#include "UseCreatedLibraries.hpp"

int main()
{
    Code::UseCreatedLibs::InvokeLambdaCpp11Style();
    Code::UseCreatedLibs::UseLibrary();

#ifdef CREATE_AND_USE_LIBRARIES
    std::cout << "CREATE_AND_USE_LIBRARIES is ON\n";
#else
    std::cout << "CREATE_AND_USE_LIBRARIES is OFF\n";
#endif
}
