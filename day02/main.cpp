#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    std::ifstream input("../input.txt");
    std::string line;
    int sum{};

    while (std::getline(input, line)) {
        std::vector<int> data{};
        std::istringstream LineStream(line);
        int number;
        while (LineStream >> number) {
            data.push_back(number);
        }
        bool successPos = true, successNeg = true;
        for (int i = 0; i < data.size()-1; i++) {
            if (data[i] > data[i+1] && data[i] - data[i+1] < 4 && data[i] - data[i+1] > 0) {}
            else {
                successPos = false;
                break;
            }
        }

        for (int i = 0; i < data.size()-1; i++) {
            if (data[i+1] > data[i] && data[i+1] - data[i] < 4 && data[i+1] - data[i] > 0) {}
            else {
                successNeg = false;
                break;
            }
        }

        if (successPos || successNeg) {
            sum++;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}