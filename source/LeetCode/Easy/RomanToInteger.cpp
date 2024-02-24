#include <unordered_map>
#include "Declarations.h"

namespace LeetCodeEasy
{
    int Solutions::RomanToInteger(const std::string &string)
    {
        int result = 0;
        std::unordered_map<char, int> values =
        {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 },
        };

        for (int i = 0; i < string.length(); i++)
            result += values[string[i]] * (i == string.length() - 1 || values[string[i]] >= values[string[i + 1]] ? 1 : -1);

        return result;
    }
}