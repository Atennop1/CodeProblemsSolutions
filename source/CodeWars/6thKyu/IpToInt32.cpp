#include <string>

namespace SixthKyu
{
    uint32_t IpToInt32(const std::string& ip)
    {
        size_t pos;
        int bytes_count = 3;
        int ip_number;

        std::string ip_copy = ip;
        std::string token;
        uint32_t result = 0;

        while ((pos = ip_copy.find('.')) != std::string::npos)
        {
            token = ip_copy.substr(0, pos);
            ip_copy.erase(0, pos + 1);

            ip_number = std::stoi(token);
            result += ip_number << (bytes_count * 8);
            bytes_count--;
        }

        ip_number = std::stoi(ip_copy);
        result += ip_number;

        return result;
    }
}