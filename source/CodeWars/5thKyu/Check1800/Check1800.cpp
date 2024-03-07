#include <string>
#include <set>
#include <vector>
#include <map>
#include "Words.h"

namespace FifthKyu
{
    std::map<int, std::string> digits_to_words =
    {
        { 2, "ABC" },
        { 3, "DEF" },
        { 4, "GHI" },
        { 5, "JKL" },
        { 6, "MNO" },
        { 7, "PQRS" },
        { 8, "TUV" },
        { 9, "WXYZ" }
    };

    int GetKeyByValue(const char &character)
    {
        for (int i = 2; i <= 9; i++)
        {
            std::string characters = digits_to_words[i];

            for (char j : characters)
                if (j == character)
                    return i;
        }

        return 0;
    }

    std::vector<std::string> GetVariationsForWord(const std::string &word)
    {
        std::vector<std::string> result;
        std::string composed_word;

        std::string first_characters = digits_to_words[GetKeyByValue(word[0])];
        std::string second_characters = digits_to_words[GetKeyByValue(word[1])];
        std::string third_characters = digits_to_words[GetKeyByValue(word[2])];
        std::string fourth_characters = (word.length() == 4 ? digits_to_words[GetKeyByValue(word[3])] : "0");

        for (int i = 0; i < (int)first_characters.length(); i++)
        {
            for (int j = 0; j < (int)second_characters.length(); j++)
            {
                for (int k = 0; k < (int)third_characters.length(); k++)
                {
                    for (int l = 0; l < (int)fourth_characters.length(); l++)
                    {
                        composed_word = "";
                        composed_word += ((int)first_characters.length() == i ? first_characters[i - 1] : first_characters[i]);
                        composed_word += ((int)second_characters.length() == j ? second_characters[j - 1] : second_characters[j]);
                        composed_word += ((int)third_characters.length() == k ? third_characters[k - 1] : third_characters[k]);

                        if (word.length() == 4)
                            composed_word += ((int)fourth_characters.length() == l ? fourth_characters[l - 1] : fourth_characters[l]);

                        for (const std::string &accepted_word : allowed_words)
                        {
                            if (accepted_word == composed_word)
                            {
                                result.push_back(composed_word);
                                break;
                            }
                        }
                    }
                }
            }
        }

        return result;
    }

    std::set<std::string> Check1800(const std::string &phone)
    {
        std::string first_word = (phone[9] == '-' ? std::string(&phone[6], &phone[9]) : std::string(&phone[6], &phone[10]));
        std::string second_word = (phone[9] == '-' ? std::string(&phone[10], &phone[14]) : std::string(&phone[11], &phone[14]));

        std::vector<std::string> first_word_variations = GetVariationsForWord(first_word);
        std::vector<std::string> second_word_variations = GetVariationsForWord(second_word);

        std::vector<std::string> another_variations = GetVariationsForWord((first_word.length() == 3 ? first_word + second_word[0] : std::string(&first_word[0], &first_word[3])));
        first_word_variations.insert(first_word_variations.end(), another_variations.begin(), another_variations.end());
        another_variations = GetVariationsForWord((second_word.length() == 3 ? first_word[first_word.length() - 1] + second_word : std::string(&second_word[1], &second_word[4])));
        second_word_variations.insert(second_word_variations.end(), another_variations.begin(), another_variations.end());

        std::set<std::string> result;
        for (const std::string& first_word_variation : first_word_variations)
            for (const std::string& second_word_variation : second_word_variations)
                if (((int)first_word_variation.length() == 3 && (int)second_word_variation.length() == 4) || ((int)first_word_variation.length() == 4 && (int)second_word_variation.length() == 3))
                    result.insert(std::string("1-800-").append(first_word_variation).append("-").append(second_word_variation));

        return result;
    }
}