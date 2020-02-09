#include <iostream>
#include <string>
#include <algorithm>
#include <map>

bool isSixDigitsLong(const std::string& digits)
{
    return digits.length() == 6;
}

bool doesDigitsNeverDecrease(const std::string& digits)
{
    return digits[0] <= digits[1]
           and digits[1] <= digits[2]
           and digits[2] <= digits[3]
           and digits[3] <= digits[4]
           and digits[4] <= digits[5];
}

bool doesAnyOfAdjacentDigitsAreTheSame(const std::string& digits)
{
    std::map<char, int> theSameDigitsPairOccurrence;
    for (auto i = 0; i < digits.length() - 1; ++i)
    {
        if (digits[i] == digits[i+1])
        {
            if (theSameDigitsPairOccurrence.find(digits[i]) == theSameDigitsPairOccurrence.end())
            {
                theSameDigitsPairOccurrence[digits[i]] = 1;
            }
            else
            {
                ++theSameDigitsPairOccurrence[digits[i]];
            }
        }
    }

    return std::any_of(theSameDigitsPairOccurrence.begin(), theSameDigitsPairOccurrence.end(), [](const auto& digit)
    {
        return digit.second == 1;
    });
}

int main()
{
    int numbersThatMeetCriteria = 0u;
    constexpr const int lowerBound = 136818u;
    constexpr const int upperBound = 685979u;

    for (auto number = lowerBound; number <= upperBound; ++number)
    {
        if (std::string digits(std::to_string(number));
                isSixDigitsLong(digits) and
                doesDigitsNeverDecrease(digits) and
                doesAnyOfAdjacentDigitsAreTheSame(digits))
        {
            ++numbersThatMeetCriteria;
        }
    }

    std::cout << numbersThatMeetCriteria << " numbers meet that criteria\n";

    return 0;
}

