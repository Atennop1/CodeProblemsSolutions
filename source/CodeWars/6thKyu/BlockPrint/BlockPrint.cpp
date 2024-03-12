#include <string>
#include <vector>
#include <map>

namespace SixthKyu
{
    extern std::map<char, std::vector<std::string>> alpha;

    std::string BlockPrint(const std::string &input)
    {
        int start = 0;
        int end = (int)input.size() - 1;

        while (input[start] == ' ' || input[end] == ' ')
        {
            if (input[start] == ' ')
                start++;

            if (input[end] == ' ')
                end--;
        }

        std::string result;
        std::string message = std::string(&input[start], &input[end]);

        for (int i = 0; i < 7; i++)
        {
            for (char letter : message)
                result += alpha[(char)(letter > 'Z' ? letter : letter + 32)][i] + ' ';

            result += '\n';
        }

        return result;
    }
}