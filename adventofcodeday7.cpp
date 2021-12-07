#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday7input.txt");

    vector<int> v;

    string x;

    while (getline(inFile, x, ',')) {
         v.push_back(stoi(x));
    }

    long sum = 0;
    long lowestSum = 0;

    for (int i = 0; i <= *max_element(v.begin(), v.end()); i++) {
        
        sum = 0;

        for (int j = 0; j < v.size(); j++) {
            sum += abs(v[j] - i);
        }

        if ((lowestSum == 0) || (sum < lowestSum)) {
            lowestSum = sum;
        }
    }

    cout << lowestSum << endl;

}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday7input.txt");

    vector<int> v;

    string x;

    while (getline(inFile, x, ',')) {
         v.push_back(stoi(x));
    }

    long sum = 0;
    long lowestSum = 0;
    long n = 0;

    for (int i = 0; i <= *max_element(v.begin(), v.end()); i++) {
        
        sum = 0;

        for (int j = 0; j < v.size(); j++) {
            n = abs(v[j] - i);
            sum += (n * (n + 1)) / 2;
        }

        if ((lowestSum == 0) || (sum < lowestSum)) {
            lowestSum = sum;
        }
    }

    cout << lowestSum << endl;

}

int main() {

    part1();

    part2();

    return 0;

}