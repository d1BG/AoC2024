#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

#define MATRIX_SIZE 140

#define HORIZONTAL 0
#define VERTICAL 1
#define LTR_DIAG 2
#define RTL_DIAG 3

struct searchMethod {
    int offset_x;
    int offset_y;
};

int main() {
    int partOneMatches=0;
    int partTwoMatches=0;

    char data[MATRIX_SIZE][MATRIX_SIZE]{};
    std::ifstream file("../input.txt");
    int lineNumber = 0;

    for (std::string line; std::getline(file, line);) {
        std::stringstream iss(line);
        int i = 0;
        for ( char character : line) {
            data[lineNumber][i++] = character;
        }
        lineNumber++;
    }
    file.close();

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            //PART ONE

            // Horizontal
            if (j <= MATRIX_SIZE - 4) {
                if ((data[i][j] == 'X' && data[i][j+1] == 'M' && data[i][j+2] == 'A' && data[i][j+3] == 'S') ||
                    (data[i][j] == 'S' && data[i][j+1] == 'A' && data[i][j+2] == 'M' && data[i][j+3] == 'X')) partOneMatches++;
            }

            // Vertical
            if (i <= MATRIX_SIZE - 4) {
                if ((data[i][j] == 'X' && data[i+1][j] == 'M' && data[i+2][j] == 'A' && data[i+3][j] == 'S') ||
                    (data[i][j] == 'S' && data[i+1][j] == 'A' && data[i+2][j] == 'M' && data[i+3][j] == 'X')) partOneMatches++;
            }

            // LTR Diag
            if (i <= MATRIX_SIZE - 4 && j <= MATRIX_SIZE - 4) {
                if ((data[i][j] == 'X' && data[i+1][j+1] == 'M' && data[i+2][j+2] == 'A' && data[i+3][j+3] == 'S') ||
                    (data[i][j] == 'S' && data[i+1][j+1] == 'A' && data[i+2][j+2] == 'M' && data[i+3][j+3] == 'X')) partOneMatches++;
            }

            // RTL Diag
            if (i <= MATRIX_SIZE - 4 && j > 2) {
                if ((data[i][j] == 'X' && data[i+1][j-1] == 'M' && data[i+2][j-2] == 'A' && data[i+3][j-3] == 'S') ||
                    (data[i][j] == 'S' && data[i+1][j-1] == 'A' && data[i+2][j-2] == 'M' && data[i+3][j-3] == 'X')) partOneMatches++;
            }

            //PART TWO
            if (i > 0 && j > 0 && i < MATRIX_SIZE-1 && j < MATRIX_SIZE-1 && data[i][j] == 'A') {
                if (data[i-1][j-1] == 'M' && data[i+1][j+1] == 'S' && data[i+1][j-1] == 'S' && data[i-1][j+1] == 'M') partTwoMatches++;
                if (data[i-1][j-1] == 'M' && data[i+1][j+1] == 'S' && data[i+1][j-1] == 'M' && data[i-1][j+1] == 'S') partTwoMatches++;
                if (data[i-1][j-1] == 'S' && data[i+1][j+1] == 'M' && data[i+1][j-1] == 'M' && data[i-1][j+1] == 'S') partTwoMatches++;
                if (data[i-1][j-1] == 'S' && data[i+1][j+1] == 'M' && data[i+1][j-1] == 'S' && data[i-1][j+1] == 'M') partTwoMatches++;
            }
        }
    }

    std::cout << "p1: "<< partOneMatches << std::endl;
    std::cout << "p2: "<< partTwoMatches << std::endl;

    return 0;
}