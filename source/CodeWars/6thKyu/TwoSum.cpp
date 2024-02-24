#include <vector>

namespace SixthKyu
{
    std::pair<std::size_t, std::size_t> TwoSum(const std::vector<int> &numbers, int target)
    {
        int count = (int) numbers.capacity();

        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (numbers[i] + numbers[j] == target)
                    return {i, j};
            }
        }

        return {0, 0};
    }
}
