#include <iostream>
#include <string>

bool doesDigitsNeverDecrease(const uint number)
{
    std::string digits(std::to_string(number));

    return digits.length() == 6
        and digits[0] <= digits[1]
        and digits[1] <= digits[2]
        and digits[2] <= digits[3]
        and digits[3] <= digits[4]
        and digits[4] <= digits[5];
}

bool doesAnyOfAdjacentDigitsAreTheSame(const uint number)
{
    std::string digits(std::to_string(number));

    if (digits.length() != 6)
    {
        return false;
    }

    for (auto i = 0; i < digits.length() - 1; ++i)
    {
        if (digits[i] == digits[i+1])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int numbersThatMeetCriteria = 0u;
    constexpr const int lowerBound = 136818u;
    constexpr const int upperBound = 685979u;

    for (auto number = lowerBound; number <= upperBound; ++number)
    {
        if(doesDigitsNeverDecrease(number) and doesAnyOfAdjacentDigitsAreTheSame(number))
        {
            ++numbersThatMeetCriteria;
        }
    }

    std::cout << numbersThatMeetCriteria << " numbers meet that criteria\n";

    return 0;
}

