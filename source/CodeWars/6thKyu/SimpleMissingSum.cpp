#include <vector>

namespace SixthKyu
{
    int Solve(std::vector<int> vector)
    {
        for (int i = 0; i < vector.size(); ++i)
        {
            for (int j = 0; j < vector.size() - i - 1; ++j)
            {
                if (vector[j] < vector[j + 1])
                {
                    int temp = vector[j];
                    vector[j] = vector[j + 1];
                    vector[j + 1] = temp;
                }
            }
        }

        int counter = 1;
        while (true)
        {
            int remains = counter;

            for (int number : vector)
                if (remains - number >= 0)
                    remains -= number;

            if (remains != 0)
                break;

            counter++;
        }

        return counter;
    }
}