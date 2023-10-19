#include <iostream>
#include "UseCreatedLibraries.hpp"
#include "HeaderLibApi.hpp"
#include "SharedLibApi.hpp"
#include "SharedOrStaticLibApi.hpp"
#include "StaticLibApi.hpp"

namespace Code
{
    namespace UseCreatedLibs
    {
        void InvokeLambdaCpp11Style()
        {
            int x {1234};
            
            auto lambda1 = [&x](int a, int b) noexcept { x++; return x <= a + b; };
            auto lambda2 = [x](int a, int b)  mutable noexcept { x++; return x <= a + b; };

            std::cout << std::boolalpha 
                << "Code::UseCreatedLibs::InvokeLambdaCpp11Style: " 
                << lambda1(1200, 35) << ", "
                << lambda1(1200, 35) << ", "
                << lambda2(1200, 35) << ", "
                << lambda2(1200, 35) << "\n";
        }

        void UseLibrary()
        {
            HeaderLib::DoPublicTask();
            SharedLib::DoPublicTask();
            SharedOrStaticLib::DoPublicTask();
            StaticLib::DoPublicTask();
        }
    
    } // ~namespace UseCreatedLibs
} // ~namespace Code
