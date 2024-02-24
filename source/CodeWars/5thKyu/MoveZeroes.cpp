#include <vector>

namespace FifthKyu
{
    std::vector<int> MoveZeroes(const std::vector<int> &input)
    {
        int moves = -1;
        std::vector<int> result = input;

        while (moves != 0)
        {
            moves = 0;

            for (int i = 0; i < result.size() - 1; ++i)
            {
                if (result[i] != 0 || result[i + 1] == 0)
                    continue;

                int temp = result[i];
                result[i] = result[i + 1];
                result[i + 1] = temp;
                moves++;
            }
        }

        return result;
    }
}