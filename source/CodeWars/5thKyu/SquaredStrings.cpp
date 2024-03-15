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

        std::string rotated;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                rotated += copy[(n * (n - j - 1)) + i];

            if (i != (n - 1))
                rotated += '\n';
        }

        return rotated;
    }

    std::string CodeSquaredStrings::Decode(const std::string &string)
    {
        int n = 0;
        while (((++n) * n) < (int)(string.length() - (n - 1))) { }

        std::string decoded;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                decoded += string[(n * (j + 1)) - i + j - 1];

        for (int i = n * n - 1; i >= 0; i--)
        {
            if (decoded[i] != '\013')
                break;

            decoded.erase(i);
        }

        return decoded;
    }
}