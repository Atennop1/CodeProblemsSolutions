#include "Alphabet.h"

namespace SixthKyu
{
    std::string BlockPrint(const std::string &input)
    {
        if (input.length() == 0)
            return "";

        int start = 0;
        int end = (int)input.size() - 1;

        while (input[start] == ' ' || input[end] == ' ')
        {
            start += (input[start] == ' ' ? 1 : 0);
            end += (input[end] == ' ' ? -1 : 0);
        }

        if (start == (int)input.length() || end == -1)
            return "";

        std::string result;
        std::string message = std::string(&input[start], &input[end] + 1);

        for (int i = 0; i < 7; i++)
        {
            for (char j : message)
                result += alpha[(char)((j > 'Z' || j == ' ') ? j : j + ' ')][i] + ' ';

            for (int j = (int)result.length() - 1; j >= 0; j--)
            {
                if (result[j] != ' ')
                    break;

                result.erase(j);
            }

            result += (i != 6 ? "\n" : "");
        }

        return result;
    }
}