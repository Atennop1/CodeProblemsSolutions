#include <iostream>

#include "CodeWars/Declarations.h"
#include "LeetCode/Declarations.h"

int main()
{
    std::vector<std::string> v = { "J vltasl rlhr ", "zdfog odxr ypw", " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!" };
    std::string result = FifthKyu::CaesarCipher::RemovingShift(v, 1);

     std::cout << result << "\n";
    return 0;
}
