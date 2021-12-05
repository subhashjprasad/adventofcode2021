#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday1input.txt");

    vector<int> v;

    int x;

    while (inFile >> x) {
        v.push_back(x);
    }

    int count = 0;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i - 1]) count++;
    }

    cout << count << endl;

}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday1input.txt");

    vector<int> v;

    int x;

    while (inFile >> x) {
        v.push_back(x);
    }

    int count = 0;
    int sumCur, sumPrev;

    for (int i = 3; i < v.size(); i++) {
        
        sumCur = v[i - 2] + v[i - 1] + v[i];
        sumPrev = v[i - 3] + v[i - 2] + v[i - 1];
        
        if (sumCur > sumPrev) count++;
    }

    cout << count << endl;

}

int main() {

    part1();

    part2();

    return 0;
}