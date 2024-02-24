#include <unordered_map>
#include "../4thKyu/Declarations.h"

namespace SixthKyu
{
    std::string LastNonEmptyString(const std::string &string)
    {
        std::string result;
        int max_count = -1;
        std::unordered_map<char, int> char_count;

        for (char c : string)
        {
            char_count[c]++;

            if (char_count[c] > max_count)
            {
                max_count = char_count[c];
                result = c;
                continue;
            }

            if (char_count[c] == max_count)
                result += c;

        }

        return result;
    }
}