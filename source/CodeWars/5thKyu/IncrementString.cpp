#include <string>

namespace FifthKyu
{
    std::string IncrementString(const std::string &input)
    {
        std::string result = input;
        int length = (int)result.length();

        if (result[length - 1] < '0' || result[length - 1] > '9')
        {
            result += '1';
            return result;
        }

        result[input.length() - 1]++;
        if (result[length - 1] == ':')
        {
            result[length - 1] = '0';
            int current_digits = 1;

            while (true)
            {
                if (result[length - current_digits - 1] + 1 == ':')
                {
                    result[length - current_digits - 1] = '0';
                    current_digits++;

                    if (result[length - current_digits - 1] >= '0' && result[length - current_digits - 1] <= '9')
                        continue;

                    result.insert(length - current_digits, 1, '1');
                    break;
                }

                result[length - current_digits - 1]++;
                break;
            }
        }

        return result;
    }
}