#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream f("input_day1.txt");

    vector<int> col1, col2;
    vector<int> result1;
    int a, b, diff, finalResult = 0, similarityScore = 0;

    while (f >> a >> b) {
        col1.push_back(a);
        col2.push_back(b);
    }
    f.close();

    sort(col1.begin(), col1.end());
    sort(col2.begin(), col2.end());

    const size_t n = col1.size();

    for (size_t i = 0; i < n; i++) {
        cout << col1[i] << "\t" << col2[i] << "\n";
    }

    for (size_t i = 0; i < n; i++) {
        if (col1[i] > col2[i]) {
            diff = col1[i]-col2[i];
        }
        else
            diff = col2[i]-col1[i];
        result1.push_back(diff);
        finalResult += result1[i];
    }

    cout<<"\n"<<finalResult<<"\n";

    for (int i = 0; i < col1.size(); i++) {
        for (int j=0; j < col2.size(); j++) {
            if (col1[i]==col2[j]) {
                similarityScore+=col1[i];
            }
        }
    }


    cout<<"\n"<<similarityScore<<"\n";
    return 0;
}
