#include <string>
#include <algorithm>

namespace FifthKyu
{
    std::string Phone(const std::string &directory, const std::string &phone_number)
    {
        std::size_t number_position = directory.find(phone_number);

        if (number_position == std::string::npos)
            return "Error => Not found: " + phone_number;

        // if there is a second number after the first number, then there are too many people on the list
        if (directory.find(phone_number, number_position + 1) != std::string::npos)
            return "Error => Too many people: " + phone_number;

        // getting start and end indexes
        int start_index = (int)number_position;
        int end_index = (int)number_position;
        while (directory[--start_index] != '\n' && start_index > 0) { }
        while (directory[++end_index] != '\n' && end_index < directory.length() - 1) { }

        // extract a needed line from directory and name from line
        std::string line = std::string(&directory[start_index + 1], &directory[end_index]);
        std::string name = std::string(&line[line.find('<') + 1], &line[line.find('>')]);
        std::string address;

        // erase number and name from line
        line.erase(line.find(phone_number), phone_number.length());
        line.erase(line.find(name), name.length());

        // filter line
        for (const char i : line)
            address += (isalpha(i) || isdigit(i) || i == '-' || i == ' ' || i == '.' ? i : ' ');

        // trim
        address.erase(address.begin(), std::find_if(address.begin(), address.end(), [](unsigned char ch) { return !std::isspace(ch); }));
        address.erase(std::find_if(address.rbegin(), address.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), address.end());

        // remove double spaces
        std::size_t double_space_index = address.find("  ");
        while (double_space_index != std::string::npos)
        {
            address.erase(double_space_index, 1);
            double_space_index = address.find("  ");
        }

        return "Phone => " + phone_number + ", Name => " + name + ", Address => " + address;
    }
}