#include <iostream>
#include <fstream>
#include <algorithm>

#define NUMBER_OF_LINES 1000

int readInputFile(int a[], int b[]);

int main() {
    int listA[NUMBER_OF_LINES]{};
    int listB[NUMBER_OF_LINES]{};
    int sum, temp = 0;
    if (readInputFile(listA, listB) == -1) {
        return -1;
    }

    std::sort(std::begin(listA), std::end(listA));
    std::sort(std::begin(listB), std::end(listB));

    for (int i = 0; i < NUMBER_OF_LINES; i++) {
        temp = listA[i] - listB[i];
        if (temp < 0)
            temp = temp * -1;
        sum += temp;
    }

    std::cout << sum << std::endl;

}

int readInputFile(int a[], int b[]) {
    std::ifstream input;
    input.open("../input.txt");
    if (!input.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }

    for (int i = 0; i < NUMBER_OF_LINES; i++) {
        input >> a[i] >> b[i];
    }

    return 0;
}