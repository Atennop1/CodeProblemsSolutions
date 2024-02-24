#include <map>
#include "Declarations.h"

namespace LeetCodeNormal
{
    std::string Solutions::IntToRoman(int number)
    {
        std::map<int, std::string> values
        {
            { 1000, "M" },
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "IX" },
            { 5, "V" },
            { 4, "IV" },
            { 1, "I" }
        };

        std::string result;
        for (auto pair = (--values.end()); pair != (--values.begin()); pair--)
        {
            while (number >= pair->first)
            {
                result += values[pair->first];
                number -= pair->first;
            }
        }

        return result;
    }
}