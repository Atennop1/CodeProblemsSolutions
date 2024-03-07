#include <string>
#include <set>
#include <vector>
#include "Words.h"

namespace FifthKyu
{
    int ToInt(const std::string &string)
    {
        int characters[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
        int result = 0;

        for (char i : string)
        {
            if (i == '-')
                continue;

            result = result * 10 + characters[i - 'A'];
        }

        return result;
    }

    std::set<std::string> Check1800_2(const std::string &phone)
    {
        std::set<std::string> result = { };
        int number = ToInt(std::string(&phone[6], &phone[14]));
        int words_digits[4] = { number / 1000, number % 1000, number / 10000, number % 10000 };
        std::vector<std::string> words[4] = { };

        for (int i = 0; i < 4; i++)
            for (const std::string &word: allowed_words)
                if (words_digits[i] == ToInt(word))
                    words[i].push_back(word);

        for (const std::string &first : words[0])
            for (const std::string &second : words[1])
                result.insert("1-800-" + first + '-' + second);

        for (const std::string &first : words[2])
            for (const std::string &second : words[3])
                result.insert("1-800-" + first + '-' + second);

        return result;
    }
}