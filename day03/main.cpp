#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int main() {
    std::ifstream input("../input.txt");
    long long int sum = 0;
    bool multiplication = true;

    for (std::string line; std::getline(input, line);) {
        std::stringstream iss(line);
        std::string data;
        for (char character : line) {
            data+=character;

            if (std::regex_search(data, std::regex(R"(do\(\))"))) {
                multiplication = true;
                data.clear();
            }

            if (std::regex_search(data, std::regex(R"(don\'t\(\))"))) {
                multiplication = false;
                data.clear();
            }

            std::smatch multipliers;
            if (multiplication && std::regex_search(data, multipliers, std::regex(R"(mul\((\d+),\s*(\d+)\))"))) {
                sum += std::stoi(multipliers[1]) * std::stoi(multipliers[2]);
                data.clear();
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}