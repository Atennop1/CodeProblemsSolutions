#include <array>
#include <string>
#include <vector>
#include <algorithm>

namespace SixthKyu
{
    unsigned int FruitMachine(const std::array<std::vector<std::string>, 3> &reels, const std::array<unsigned int, 3> &spins)
    {
        std::array<std::string, 10> items = { "Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack" };

        if (reels[0][spins[0]] == reels[1][spins[1]] && reels[1][spins[1]] == reels[2][spins[2]])
            return (10u - std::distance(&items[0], std::find(&items[0], &items[9], reels[0][spins[0]]))) * 10;

        if (reels[0][spins[0]] == reels[1][spins[1]] || reels[1][spins[1]] == reels[2][spins[2]] || reels[0][spins[0]] == reels[2][spins[2]])
        {
            unsigned int different_index = 3 - (reels[0][spins[0]] == reels[1][spins[1]] ? 1 : (reels[1][spins[1]] == reels[2][spins[2]] ? 3 : 2));
            unsigned int same_index = (reels[0][spins[0]] == reels[1][spins[1]] ? 0 : (reels[1][spins[1]] == reels[2][spins[2]] ? 1 : 0));
            return (10u - std::distance(&items[0], std::find(&items[0], &items[9], reels[same_index][spins[same_index]]))) * (reels[different_index][spins[different_index]] == "Wild" ? 2 : 1);
        }

        return 0;
    }
}