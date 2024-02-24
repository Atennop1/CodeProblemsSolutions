#include "Declarations.h"

namespace LeetCodeEasy
{
    int Solutions::RemoveElement(std::vector<int> &numbers, int removing_number)
    {
        int k = 0;

        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == removing_number)
            {
                numbers.erase(numbers.begin() + i);
                i--;
                continue;
            }

            k++;
        }

        return k;
    }
}
