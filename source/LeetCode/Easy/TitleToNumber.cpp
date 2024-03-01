#include <string>
#include <cmath>
#include "Declarations.h"

namespace LeetCodeEasy
{
    int Solutions::TitleToNumber(const std::string &column_title)
    {
        int result = 0;

        for (int i = 0; i < column_title.length(); i++)
            result += (column_title[column_title.length() - i - 1] - '@') * int(std::pow(26, i));

        return result;
    }
}