#include <string>
#include "Declarations.h"

namespace LeetCodeEasy
{
    bool Solutions::IsPalindrome(const std::string &string)
    {
        // slowest but simplest way, optimized way is two pointers comparison
        std::string filtered;

        for (const char &character: string)
            if (isalpha(character) || isdigit(character))
                filtered += tolower(character);

        for (int i = 0; i < filtered.length() / 2; i++)
            if (filtered[i] != filtered[filtered.length() - i - 1])
                return false;

        return true;
    }
}