#include <vector>
#include <set>
#include <algorithm>
#include "Declarations.h"

namespace LeetCodeEasy
{
    int Solutions::SingleNumber(const std::vector<int> &numbers)
    {
        std::set<int> numbers_set;

        for (const int &i : numbers)
        {
            if (numbers_set.find(i) != numbers_set.end())
            {
                numbers_set.erase(i);
                continue;
            }

            numbers_set.insert(i);
        }

        return *numbers_set.begin();
    }
}