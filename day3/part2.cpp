#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <limits>
#include <algorithm>

int main()
{
    std::ifstream inputFile;
    inputFile.open("../input.txt");

    std::string firstLine;
    std::string secondLine;

    std::getline(inputFile, firstLine);
    std::getline(inputFile, secondLine);

    inputFile.close();

    std::stringstream firstStream(firstLine);
    std::stringstream secondStream(secondLine);

    std::vector<std::pair<char, uint>> firstWire;
    std::vector<std::pair<char, uint>> secondWire;

    for (std::string partOfWire; std::getline(firstStream, partOfWire, ',');)
    {
        firstWire.emplace_back(partOfWire[0], std::stoi(partOfWire.substr(1)));
    }

    for (std::string partOfWire; std::getline(secondStream, partOfWire, ',');)
    {
        secondWire.emplace_back(partOfWire[0], std::stoi(partOfWire.substr(1)));
    }

    std::map<char, std::pair<int, int>> directions =
    {
        {'L', {-1,0}},
        {'R', {1, 0}},
        {'U', {0, 1}},
        {'D', {0, -1}}
    };

    std::map<std::pair<int, int>, int> locationsAndDistance;
    int x1 = 0, y1 = 0, distance1 = 0;

    for (const auto& [direction, distance] : firstWire)
    {
        const auto [directionX, directionY] = directions[direction];
        for (auto i = 1u; i <= distance; ++i)
        {
            x1 += directionX;
            y1 += directionY;
            locationsAndDistance.insert({{x1, y1}, ++distance1});
        }
    }

    int minLengthOfWires(std::numeric_limits<int>::max());
    int x2 = 0, y2 = 0, distance2 = 0;

    for (const auto& [direction, distance] : secondWire)
    {
        const auto [directionX, directionY] = directions[direction];
        for (auto i = 1u; i <= distance; ++i)
        {
            x2 += directionX;
            y2 += directionY;
            ++distance2;

            if (const auto intersection = locationsAndDistance.find({x2, y2});
                intersection != locationsAndDistance.end())
            {
                const auto lengthOfWires = distance2 + intersection->second;
                if (lengthOfWires < minLengthOfWires)
                {
                    minLengthOfWires = lengthOfWires;
                }
            }
        }
    }

    std::cout << minLengthOfWires << "\n";

    return 0;
}

