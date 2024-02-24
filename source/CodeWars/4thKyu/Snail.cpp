#include <algorithm>
#include "Declarations.h"

namespace FourthKyu
{
    std::vector<int> Snail(const std::vector<std::vector<int>> &matrix)
    {
        if (matrix[0].empty())
            return { };

        int current_x = 0;
        int current_y = 0;
        int current_step_x = 1;
        int current_step_y = 0;

        std::vector<int> result = { };
        std::vector<std::pair<int, int>> used_indexes = { };

        for (int _ = 0; _ < (int)(matrix.size() * matrix.size()); _++)
        {
            result.push_back(matrix[current_y][current_x]);
            used_indexes.emplace_back(current_x, current_y);

            int next_x = current_x + current_step_x;
            int next_y = current_y + current_step_y;
            std::pair<int, int> pair = { next_x, next_y };

            if (std::find(used_indexes.begin(), used_indexes.end(), pair) != used_indexes.end() || next_x == (int)matrix.size() || next_y == (int)matrix.size() || next_x == -1 || next_y == -1)
            {
                int new_step_x = ((current_step_x == 1 || current_step_x == -1) ? 0 : -current_step_y);
                current_step_y = ((current_step_y == 1 || current_step_y == -1) ? 0 : current_step_x);
                current_step_x = new_step_x;
            }

            current_x += current_step_x;
            current_y += current_step_y;
        }

        return result;
    }
}