#pragma once
#include <iostream>

namespace Code
{
    namespace HeaderLib
    {

        void InvokeLambdaCpp14Style()
        {
            int x {123};
            
            auto lambda = [&x, y = -4, z = 5.6f](auto a, auto b) noexcept { x++; return x + y + z - a - b; };

            std::cout << std::boolalpha 
                << "Code::HeaderLib::InvokeLambdaCpp14Style: " 
                << lambda(100u, 5.5) << "\n";
        }
        
    
    } // ~namespace HeaderLib
} // ~namespace Code
