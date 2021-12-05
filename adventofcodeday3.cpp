#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday3input.txt");

    vector<string> v;

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    string gamma = "";
    string epsilon = "";
    
    int count0;
    int count1;
    
    for (int k = 0; k < 12; k++) {

        count0 = 0;
        count1 = 0;

        for (int i = 0; i < v.size(); i++) {
            if ((v[i])[k] == '0') count0++;
            else count1++;
        }

        if (count0 > count1) {
            gamma += "0";
            epsilon += "1";
        } else {
            gamma += "1";
            epsilon += "0";
        }
    }
    
    cout << stoi(gamma, 0, 2) * stoi(epsilon, 0, 2) << endl;
}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday3input.txt");

    vector<string> numsox;
    vector<string> numsco;

    string x;

    while (inFile >> x) {
        numsox.push_back(x);
        numsco.push_back(x);
    }

    string ox = "";
    string co = "";
    
    int count0;
    int count1;
    
    for (int k = 0; k < 12; k++) {

        count0 = 0;
        count1 = 0;

        for (int i = 0; i < numsox.size(); i++) {
            if ((numsox[i])[k] == '0') count0++;
            else count1++;
        }

        if (count0 > count1) {
            for (int i = 0; i < numsox.size(); i++) {
                if ((numsox[i])[k] == '1') {
                    numsox.erase(numsox.begin() + i);
                    i--;
                }
            }
        } else {
            for (int i = 0; i < numsox.size(); i++) {
                if ((numsox[i])[k] == '0') {
                    numsox.erase(numsox.begin() + i);
                    i--;
                }
            }
        }

    }
    
    ox = numsox[0];
    
    for (int k = 0; k < 12; k++) {

        count0 = 0;
        count1 = 0;

        for (int i = 0; i < numsco.size(); i++) {
            if ((numsco[i])[k] == '0') count0++;
            else count1++;
        }
        if (count0 <= count1) {
            for (int i = 0; i < numsco.size(); i++) {
                if ((numsco[i])[k] == '1') {
                    numsco.erase(numsco.begin() + i);
                    i--;
                }
            }
        } else {
            for (int i = 0; i < numsco.size(); i++) {
                if ((numsco[i])[k] == '0') {
                    numsco.erase(numsco.begin() + i);
                    i--;
                }
            }
        }

    }
    
    co = numsco[0];
    
    cout << stoi(ox, 0, 2) * stoi(co, 0, 2) << endl;
}

int main() {

    part1();

    part2();
    
    return 0;
}