#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int countMASDiagonalCrosses(const std::string& grid, int size) {
    int counter = 0;

    for (int row = 1; row < size - 1; ++row) {
        for (int col = 1; col < size - 1; ++col) {
            int center = row * size + col;
            if (grid[center] != 'A') continue;

            int left_up    = (row - 1) * size + (col - 1);
            int right_down = (row + 1) * size + (col + 1);
            int right_up   = (row - 1) * size + (col + 1);
            int left_down  = (row + 1) * size + (col - 1);

            int halfCounter = 0;

            if ((grid[left_up] == 'M' && grid[right_down] == 'S') ||
                (grid[left_up] == 'S' && grid[right_down] == 'M')) {
                halfCounter++;
                }

            if ((grid[right_up] == 'M' && grid[left_down] == 'S') ||
                (grid[right_up] == 'S' && grid[left_down] == 'M')) {
                halfCounter++;
                }

            if (halfCounter == 2) {
                counter++;
            }
        }
    }

    return counter;
}

int main() {
    std::ifstream f("input_day4.txt");
    std::string line;
    std::vector<std::string> gridRows;

    while (std::getline(f, line)) {
        gridRows.push_back(line);
    }

    const int size = gridRows.size();

    std::string flatGrid;
    for (const auto& row : gridRows) {
        flatGrid += row;
    }

    int result = countMASDiagonalCrosses(flatGrid, size);
    std::cout << "Diagonal MAS/SAM crosses (with 'A' in center): " << result << std::endl;

    return 0;
}
