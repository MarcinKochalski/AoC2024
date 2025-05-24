#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream f("input_day3.txt");
    string line;
    vector<string> exactString;
    int finalResult = 0;
    int toggle = 1;

    while (getline(f, line)) {
        exactString.push_back(line);
    }

    for (const string& str : exactString) {

        for (size_t i = 0; i + 6 < str.size(); i++) {

            if (str[i] == 'd' && str[i+1] == 'o' && str[i+2] == '(' && str[i+3] == ')')
                toggle = 1;
            if (str[i] == 'd' && str[i+1] == 'o' && str[i+2] == 'n' && str[i+3] == '\'' && str[i+4] == 't' && str[i+5] == '(' && str[i+6] == ')')
                toggle = 0;
            if (str[i] == 'm' && str[i+1] == 'u' && str[i+2] == 'l' && str[i+3] == '(' && toggle == 1) {
                int num1 = 0, num2 = 0;
                int j = i + 4;
                while (j < str.size() && isdigit(str[j])) {
                    num1 = num1 * 10 + (str[j] - '0');
                    j++;
                }
                if (j >= str.size() || str[j] != ',') continue;
                j++;
                while (j < str.size() && isdigit(str[j])) {
                    num2 = num2 * 10 + (str[j] - '0');
                    j++;
                }
                if (j >= str.size() || str[j] != ')') continue;

                finalResult += num1 * num2;
            }
        }

    }

    cout << finalResult << endl;
    return 0;
}
