#include <vector>
#include <string>
#include <map>
#include "Declarations.h"

namespace LeetCodeNormal
{
    std::vector<std::string> Solutions::LetterCombinations(const std::string& digits)
    {
        if (digits.empty())
            return { };

        std::map<char, std::vector<char>> letters =
        {
            { '2', { 'a', 'b', 'c' } },
            { '3', { 'd', 'e', 'f' } },
            { '4', { 'g', 'h', 'i' } },
            { '5', { 'j', 'k', 'l' } },
            { '6', { 'm', 'n', 'o' } },
            { '7', { 'p', 'q', 'r', 's' } },
            { '8', { 't', 'u', 'v' } },
            { '9', { 'w', 'x', 'y', 'z' } }
        };

        std::vector<std::string> result;
        int digits_count = (int)digits.size();
        int variants_count = 1;

        for (char digit: digits)
            variants_count *= (int) letters[digit].size();

        for (int i = 0; i < variants_count; i++)
        {
            std::string string;
            int divider = variants_count;

            for (int j = 0; j < digits_count; j++)
            {
                divider /= (int)letters[digits[j]].size();
                string += letters[digits[j]][(i / divider) % (int)letters[digits[j]].size()];
            }

            result.push_back(string);
        }

        return result;
    }
}