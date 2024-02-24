#include <unordered_map>
#include "Declarations.h"

namespace LeetCodeEasy 
{
    std::vector<int> Solutions::TwoSum(std::vector<int> &numbers, int target)
    {
        std::unordered_map<int, int> hash_table;

        for (int i = 0; i < numbers.size(); i++)
            hash_table.insert({ numbers[i], i });

        for (int i = 0; i < numbers.size(); i++)
            if (hash_table.find(target - numbers[i]) != hash_table.end() && hash_table[target - numbers[i]] != i)
                return { hash_table[target - numbers[i]], i };

        return { };
    }
}
