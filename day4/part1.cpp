#include <iostream>
#include <string>
#include <algorithm>

bool isSixDigitsLong(const uint number)
{
    return std::to_string(number).length() == 6;
}

bool doesDigitsNeverDecrease(const uint number)
{
    std::string digits(std::to_string(number));

    return digits[0] <= digits[1]
        and digits[1] <= digits[2]
        and digits[2] <= digits[3]
        and digits[3] <= digits[4]
        and digits[4] <= digits[5];
}

bool doesAnyOfAdjacentDigitsAreTheSame(const uint number)
{
    std::string digits(std::to_string(number));

    return std::adjacent_find(digits.begin(), digits.end()) != digits.end();
}

int main()
{
    int numbersThatMeetCriteria = 0u;
    constexpr const int lowerBound = 136818u;
    constexpr const int upperBound = 685979u;

    for (auto number = lowerBound; number <= upperBound; ++number)
    {
        if (isSixDigitsLong(number) and
            doesDigitsNeverDecrease(number) and
            doesAnyOfAdjacentDigitsAreTheSame(number))
        {
            ++numbersThatMeetCriteria;
        }
    }

    std::cout << numbersThatMeetCriteria << " numbers meet that criteria\n";

    return 0;
}

