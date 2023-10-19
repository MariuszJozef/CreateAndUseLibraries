#include <iostream>
#include "SharedLibApi.hpp"
#include "SharedLibPrivate.hpp"

namespace Code::SharedLib
{

void DoPublicTask()
{
    InvokeLambdaCpp17Style();
}
    
} // ~namespace Code::SharedLib
