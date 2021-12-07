#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <array>

using namespace std;

int table[1000][1000];

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday5input.txt");

    vector<int> v;

    string x;
    string subx;

    while (inFile >> x) {
        if (x != "->") {

            stringstream ss(x);

            while (ss.good()) {
                getline(ss, subx, ',');
                v.push_back(stoi(subx));
            }
        }
    }

    for (int k = 0; k < 1000; k++) {
        for (int n = 0; n < 1000; n++) {
            table[k][n] = 0;
        }
    }

    for (int i = 0; i < v.size(); i += 4) {

        if (v[i] == v[i + 2]) {

            if (v[i + 1] < v[i + 3]) {

                for (int j = v[i + 1]; j <= v[i + 3]; j++) {
                    table[v[i]][j] += 1;
                }

            } else {

                for (int j = v[i + 3]; j <= v[i + 1]; j++) {
                    table[v[i]][j] += 1;
                }

            }

        } else if (v[i + 1] == v[i + 3]) {

            if (v[i] < v[i + 2]) {

                for (int j = v[i]; j <= v[i + 2]; j++) {
                    table[j][v[i + 1]] += 1;
                }

            } else {

                for (int j = v[i + 2]; j <= v[i]; j++) {
                    table[j][v[i + 1]] += 1;
                }

            }

        }

    }

    int count = 0;

    for (int k = 0; k < 1000; k++) {
        for (int n = 0; n < 1000; n++) {
            if (table[k][n] >= 2) count++;
        }
    }

    cout << count << endl;

}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday5input.txt");

    vector<int> v;

    string x;
    string subx;

    while (inFile >> x) {
        if (x != "->") {

            stringstream ss(x);

            while (ss.good()) {
                getline(ss, subx, ',');
                v.push_back(stoi(subx));
            }
        }
    }

    for (int k = 0; k < 1000; k++) {
        for (int n = 0; n < 1000; n++) {
            table[k][n] = 0;
        }
    }

    for (int i = 0; i < v.size(); i += 4) {

        if (v[i] == v[i + 2]) {

            if (v[i + 1] < v[i + 3]) {

                for (int j = v[i + 1]; j <= v[i + 3]; j++) {
                    table[v[i]][j] += 1;
                }

            } else {

                for (int j = v[i + 3]; j <= v[i + 1]; j++) {
                    table[v[i]][j] += 1;
                }

            }

        } else if (v[i + 1] == v[i + 3]) {

            if (v[i] < v[i + 2]) {

                for (int j = v[i]; j <= v[i + 2]; j++) {
                    table[j][v[i + 1]] += 1;
                }

            } else {

                for (int j = v[i + 2]; j <= v[i]; j++) {
                    table[j][v[i + 1]] += 1;
                }

            }

        } else if ((v[i + 3] - v[i + 1] == v[i + 2] - v[i]) && (v[i + 3] - v[i + 1] >= 0) && (v[i + 2] - v[i] >= 0)) {

            for (int j = 0; j <= v[i + 2] - v[i]; j++) {
                    table[v[i] + j][v[i + 1] + j] += 1;
                }
        } else if ((v[i + 1] - v[i + 3] == v[i] - v[i + 2]) && (v[i + 1] - v[i + 3] >= 0) && (v[i] - v[i + 2] >= 0)) {

            for (int j = 0; j <= v[i] - v[i + 2]; j++) {
                    table[v[i + 2] + j][v[i + 3] + j] += 1;
                }
        } else if ((v[i + 1] - v[i + 3] == v[i + 2] - v[i]) && (v[i + 1] - v[i + 3] >= 0) && (v[i + 2] - v[i] >= 0))  {

            for (int j = 0; j <= v[i + 2] - v[i]; j++) {
                    table[v[i] + j][v[i + 1] - j] += 1;
                }
        }  else if ((v[i + 3] - v[i + 1] == v[i] - v[i + 2]) && (v[i + 3] - v[i + 1] >= 0) && (v[i] - v[i + 2] >= 0)) {

            for (int j = 0; j <= v[i] - v[i + 2]; j++) {
                    table[v[i + 2] + j][v[i + 3] - j] += 1;
                }
        } 

    }

    int count = 0;

    for (int k = 0; k < 1000; k++) {
        for (int n = 0; n < 1000; n++) {
            if (table[k][n] >= 2) count++;
        }
    }

    cout << count << endl;

}

int main() {

    part1();

    part2();

    return 0;

}