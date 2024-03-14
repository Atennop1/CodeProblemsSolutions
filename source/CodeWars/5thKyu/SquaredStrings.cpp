#include <string>
#include "Declarations.h"

namespace FifthKyu
{
    std::string CodeSquaredStrings::Code(const std::string &string)
    {
        int n = 0;
        while (((++n) * n) < (int)string.length()) { }

        std::string copy = string;
        for (int _ = 0; _ < n * n - (int)string.length(); _++)
            copy += '\013';

        std::string squared;
        for (int i = 0; i < n; i++)
        {
            squared += std::string(&copy[i * n], &copy[(i + 1) * n]);
            squared += '\n';
        }

        std::string rotated;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                rotated += squared[(n * (n - j)) + i - j - 1];

            if (i != (n - 1))
                rotated += '\n';
        }

        return rotated;
    }

    std::string CodeSquaredStrings::Decode(const std::string &string)
    {
        int n = 0;
        while (((++n) * n) < (int)(string.length() - (n - 1))) { }

        std::string not_rotated;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                not_rotated += string[(n * (j + 1)) - i + j - 1];

        std::string not_squared;
        for (const char &character : not_rotated)
            if (character != '\n')
                not_squared += character;

        for (int i = n * n - 1; i >= 0; i--)
        {
            if (not_rotated[i] != '\013')
                break;

            not_squared.erase(i);
        }

        return not_squared;
    }
}