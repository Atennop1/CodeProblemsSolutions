#include <vector>
#include <valarray>

namespace SixthKyu
{
    static long FindMissing(std::vector<long> list)
    {
        int last_difference = list[1] - list[0];

        for (int i = 1; i < (int)(list.size() - 1); ++i)
        {
            if (std::abs(list[i + 1] - list[i]) > std::abs(last_difference))
                return list[i] + ((list[i + 1] - list[i]) / 2);

            if (std::abs(list[i + 1] - list[i]) < std::abs(last_difference))
                return list[i] - (last_difference / 2);
        }

        return 0;
    }
}