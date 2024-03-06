#include <iostream>

#include "CodeWars/Declarations.h"
#include "LeetCode/Declarations.h"

int main()
{
    auto result = FifthKyu::Check1800("1-800-INK-WANT");

    for (const std::string &str : result)
        std::cout << str << '\n';

    return 0;
}
