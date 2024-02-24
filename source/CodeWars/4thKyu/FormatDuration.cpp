#include "Declarations.h"

namespace FourthKyu
{
    struct TimeUnit
    {
    public:
        int amount;
        std::string name;

        TimeUnit()
            : amount(0) { }

        TimeUnit(const std::string &constructor_name, int constructor_amount)
        {
            name = constructor_name;
            amount = constructor_amount;
        }
    };

    std::string FormatDuration(int seconds)
    {
        if (seconds == 0)
            return "now";

        std::string result;
        TimeUnit units[5];

        units[0] = TimeUnit("year", seconds / (60 * 60 * 24 * 365));
        units[1] = TimeUnit("day", (seconds -= units[0].amount * (60 * 60 * 24 * 365)) / (60 * 60 * 24));
        units[2] = TimeUnit("hour", (seconds -= units[1].amount * (60 * 60 * 24)) / (60 * 60));
        units[3] = TimeUnit("minute", (seconds -= units[2].amount * (60 * 60)) / 60);
        units[4] = TimeUnit("second", (seconds -= units[3].amount * 60));

        int count_of_non_zeroes = 0;
        for (const TimeUnit &unit: units)
            count_of_non_zeroes += unit.amount == 0 ? 0 : 1;

        for (const TimeUnit &unit : units)
        {
            if (unit.amount == 0)
                continue;

            result += std::to_string(unit.amount) + " " + unit.name + (unit.amount > 1 ? "s" : "");
            count_of_non_zeroes--;

            if (count_of_non_zeroes > 1)
            {
                result += ", ";
                continue;
            }

            if (count_of_non_zeroes == 1)
                result += " and ";
        }

        return result;
    }
}