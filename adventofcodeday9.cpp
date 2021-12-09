#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int table[100][100];
int basinSum = 0;

void search(int t[100][100], int j, int i) {
    table[j][i] = 9;
    if ((j != 0) && (t[j - 1][i] != 9)) search(t, j - 1, i);
    if ((j != 99) && (t[j + 1][i] != 9)) search(t, j + 1, i);
    if ((i != 0) && (t[j][i - 1] != 9)) search(t, j, i - 1);
    if ((i != 99) && (t[j][i + 1] != 9)) search(t, j, i + 1);
    basinSum++;
}

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday9input.txt");

    vector<string> v;

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            table[j][i] = stoi((v[i]).substr(j, 1));
        }
    }

    int sum = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (((j == 0) || (table[j - 1][i] > table[j][i])) && ((j == 99) || (table[j + 1][i] > table[j][i])) && ((i == 0) || (table[j][i - 1] > table[j][i])) && ((i == 99) || (table[j][i + 1] > table[j][i]))) {
                sum += table[j][i] + 1;
            }
        }
    }

    cout << sum << endl;

}

void part2() {
    
    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday9input.txt");

    vector<string> v;

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            table[j][i] = stoi((v[i]).substr(j, 1));
        }
    }

    vector<int> basins;
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (table[j][i] != 9) {
                basinSum = 0;
                search(table, j, i);
                basins.push_back(basinSum);
            }
        }
    }

    int multiplyMax = *max_element(basins.begin(), basins.end());

    for (int i = 0; i < basins.size(); i++) {
        if (basins[i] == *max_element(basins.begin(), basins.end())) basins.erase(basins.begin() + i);
    }

    multiplyMax *= *max_element(basins.begin(), basins.end());

    for (int i = 0; i < basins.size(); i++) {
        if (basins[i] == *max_element(basins.begin(), basins.end())) basins.erase(basins.begin() + i);
    }

    multiplyMax *= *max_element(basins.begin(), basins.end());

    cout << multiplyMax << endl;

}

int main() {

    part1();

    part2();

    return 0;
}