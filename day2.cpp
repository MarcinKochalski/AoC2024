#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool isStrictlySafe(const vector<int>& row) {
    if (row.size() < 2) return false;

    int direction = row[1] - row[0];
    if (direction == 0 || abs(direction) > 3) return false;

    bool isIncreasing = direction > 0;

    for (size_t i = 0; i < row.size() - 1; ++i) {
        int diff = row[i + 1] - row[i];

        if (diff == 0 || abs(diff) > 3) return false;
        if (isIncreasing && diff <= 0) return false;
        if (!isIncreasing && diff >= 0) return false;
    }
    return true;
}

int main() {
    ifstream f("input_day2.txt");
    string line;
    int safe = 0;

    while (getline(f, line)) {
        istringstream iss(line);
        vector<int> row;
        int num;

        while (iss >> num) {
            row.push_back(num);
        }

        if (isStrictlySafe(row)) {
            safe++;
            continue;
        }

        bool foundSafeVersion = false;
        for (size_t i = 0; i < row.size(); ++i) {
            vector<int> testRow = row;
            testRow.erase(testRow.begin() + i);

            if (isStrictlySafe(testRow)) {
                foundSafeVersion = true;
                break;
            }
        }

        if (foundSafeVersion) {
            safe++;
        }
    }

    cout << safe << endl;
    return 0;
}
