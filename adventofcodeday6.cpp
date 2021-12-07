#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Fish {

    int timer;

    Fish(int t) {
        timer = t;
    }

    int advanceDay() {

        if (timer > 0) {
            timer--;
            return 0;
        } else {
            timer = 6;
            return 1;
        }

    }

};

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday6input.txt");

    vector<int> v;

    string x;

    while (getline(inFile, x, ',')) {
         v.push_back(stoi(x));
    }

    vector<Fish> fishSchool;

    for (int i = 0; i < v.size(); i++) {
        Fish f(v[i]);
        fishSchool.push_back(f);
    }

    int size;

    for (int i = 0; i < 80; i++) {
        
        size = fishSchool.size();

        for (int j = 0; j < size; j++) {
            if (fishSchool[j].advanceDay() == 1) {
                Fish f(8);
                fishSchool.push_back(f);
            }
            
        }

    }

    cout << fishSchool.size() << endl;

}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday6input.txt");

    vector<int> v;

    string x;

    while (getline(inFile, x, ',')) {
         v.push_back(stoi(x));
    }

    unsigned long long fishSchool[9];

    for (int i = 0; i < 9; i++) {
        fishSchool[i] = 0;
    }

    for (int i = 0; i < v.size(); i++) {
        fishSchool[v[i]] += 1;
    }

    unsigned long long newFish = 0;

    for (int i = 0; i < 256; i++) {

        newFish = fishSchool[0];

        for (int j = 0; j < 8; j++) {
            fishSchool[j] = fishSchool[j + 1];
        }

        fishSchool[6] += newFish;

        fishSchool[8] = newFish;
    }

    unsigned long long sum = 0;

    for (int i = 0; i < 9; i++) {
        sum += fishSchool[i];
    }

    cout << sum << endl;

}

int main() {

    part1();

    part2();

    return 0;

}