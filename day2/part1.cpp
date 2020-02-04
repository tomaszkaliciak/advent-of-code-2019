#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
    std::vector<int> codes;
    std::ifstream inputFile;
    inputFile.open("../input.txt");

    for (std::string code; std::getline(inputFile, code, ',');)
    {
        codes.emplace_back(std::stoi(code));
    }

    inputFile.close();

    codes[1] = 12;
    codes[2] = 2;

    for (auto i = 0; i < codes.size() - 4; i += 4)
    {
        const auto operationType = codes[i];
        if (operationType == 1)
        {
            codes[codes[i + 3]] = codes[codes[i + 1]] + codes[codes[i + 2]];
        }
        else if (operationType == 2)
        {
            codes[codes[i + 3]] = codes[codes[i + 1]] * codes[codes[i + 2]];
        }
        else
        {
            break;
        }
    }

    std::cout << codes[0] << "\n";

    return 0;
}

