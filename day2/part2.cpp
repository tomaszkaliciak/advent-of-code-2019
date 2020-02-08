#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
    std::vector<int> memory;
    std::ifstream inputFile;
    inputFile.open("../input.txt");

    for (std::string code; std::getline(inputFile, code, ',');)
    {
        memory.emplace_back(std::stoi(code));
    }

    inputFile.close();

    constexpr const auto desiredOutput = 19690720u;

    for (auto noun = 0; noun < 100; ++noun)
    {
        for (auto verb = 0; verb < 100; ++verb)
        {
            std::vector<int> currentMemory(memory);
            currentMemory[1] = noun;
            currentMemory[2] = verb;

            for (auto i = 0; currentMemory[i] != 99; i += 4)
            {
                const auto operationType = currentMemory[i];
                if (operationType == 1)
                {
                    currentMemory[currentMemory[i + 3]] =
                            currentMemory[currentMemory[i + 1]] + currentMemory[currentMemory[i + 2]];
                }
                else
                {
                    currentMemory[currentMemory[i + 3]] =
                            currentMemory[currentMemory[i + 1]] * currentMemory[currentMemory[i + 2]];
                }
            }

            if (currentMemory[0] == desiredOutput)
            {
                const auto correctNoun = currentMemory[1], correctVerb = currentMemory[2];
                std::cout << "noun " << correctNoun << " verb: " << correctVerb << "\n";
                std::cout << "output = " << 100 * correctNoun + correctVerb << "\n";
                return 0;
            }
        }
    }

    return 0;
}

