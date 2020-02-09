#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <limits>

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

    std::set<std::pair<int, int>> locations;
    int x1 = 0, y1 = 0;

    for (const auto& [direction, distance] : firstWire)
    {
        const auto [directionX, directionY] = directions[direction];
        for (auto i = 1u; i <= distance; ++i)
        {
            x1 += directionX;
            y1 += directionY;
            locations.emplace(x1, y1);
        }
    }

    int minManhattanDistance(std::numeric_limits<int>::max());
    int x2 = 0, y2 = 0;

    for (const auto& [direction, distance] : secondWire)
    {
        const auto [directionX, directionY] = directions[direction];
        for (auto i = 1u; i <= distance; ++i)
        {
            x2 += directionX;
            y2 += directionY;
            if (locations.find({x2, y2}) != locations.end())
            {
                const auto manhattanDistanceFromIntersection = std::abs(x2) + std::abs(y2);
                if (manhattanDistanceFromIntersection < minManhattanDistance)
                {
                    minManhattanDistance = manhattanDistanceFromIntersection;
                }
            }
        }
    }

    std::cout << minManhattanDistance << "\n";

    return 0;
}

