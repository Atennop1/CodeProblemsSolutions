#include "Declarations.h"

namespace LeetCodeEasy
{
    std::string Solutions::LongestCommonPrefix(std::vector<std::string> &strings)
    {
        std::string result;

        for (int i = 0; i > -1; i++)
        {
            if (strings.empty())
                break;

            if (strings.size() == 1)
                return strings[0];

            for (int j = 0; j < strings.size() - 1; j++)
                if (strings[j].empty() || strings[j].size() == i || (strings[j][i] != strings[j + 1][i]))
                    return result;

            result += strings[0][i];
        }

        return result;
    }
}