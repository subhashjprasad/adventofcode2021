#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int table[10][10];
bool tableB[10][10];
int flashSum = 0;

void flash(int j, int i) {
    flashSum++;
    if (j != 0) {
        table[j - 1][i]++;
        if ((table[j - 1][i] > 9) && (tableB[j - 1][i] == false)) {
            tableB[j - 1][i] = true;
            flash(j - 1, i);
            
        }
    }
    if (j != 9) {
        table[j + 1][i]++;
        if ((table[j + 1][i] > 9) && (tableB[j + 1][i] == false)) {
            tableB[j + 1][i] = true;
            flash(j + 1, i);
            
        }
    }
    if (i != 0) {
        table[j][i - 1]++;
        if ((table[j][i - 1] > 9) && (tableB[j][i - 1] == false)) {
            tableB[j][i - 1] = true;
            flash(j, i - 1);
            
        }
    }
    if (i != 9) {
        table[j][i + 1]++;
        if ((table[j][i + 1] > 9) && (tableB[j][i + 1] == false)) {
            tableB[j][i + 1] = true;
            flash(j, i + 1);
            
        }
    }
    if ((j != 0) && (i != 0)) {
        table[j - 1][i - 1]++;
        if ((table[j - 1][i - 1] > 9) && (tableB[j - 1][i - 1] == false)) {
            tableB[j - 1][i - 1] = true;
            flash(j - 1, i - 1);
            
        }
    }
    if ((j != 0) && (i != 9)) {
        table[j - 1][i + 1]++;
        if ((table[j - 1][i + 1] > 9) && (tableB[j - 1][i + 1] == false)) {
            tableB[j - 1][i + 1] = true;
            flash(j - 1, i + 1);
            
        }
    }
    if ((j != 9) && (i != 0)) {
        table[j + 1][i - 1]++;
        if ((table[j + 1][i - 1] > 9) && (tableB[j + 1][i - 1] == false)) {
            tableB[j + 1][i - 1] = true;
            flash(j + 1, i - 1);
            
        }
    }
    if ((j != 9) && (i != 9)) {
        table[j + 1][i + 1]++;
        if ((table[j + 1][i + 1] > 9) && (tableB[j + 1][i + 1] == false)) {
            tableB[j + 1][i + 1] = true;
            flash(j + 1, i + 1);
            
        }
    }
    
}

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday11input.txt");

    vector<string> v;

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            table[j][i] = stoi((v[i]).substr(j, 1));
        }
    }

    for (int k = 0; k < 100; k++) {

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                tableB[j][i] = false;
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                table[j][i]++;
            }
        }


        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if ((table[j][i] > 9) && (tableB[j][i] == false)) {
                    tableB[j][i] = true;
                    flash(j, i);

                }
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (tableB[j][i] == true) table[j][i] = 0;
            }
        }

    }

    cout << flashSum << endl;
}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday11input.txt");

    vector<string> v;

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            table[j][i] = stoi((v[i]).substr(j, 1));
        }
    }

    for (int k = 0; k < 1000; k++) {

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                tableB[j][i] = false;
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                table[j][i]++;
            }
        }


        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if ((table[j][i] > 9) && (tableB[j][i] == false)) {
                    tableB[j][i] = true;
                    flash(j, i);

                }
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (tableB[j][i] == true) table[j][i] = 0;
            }
        }

        bool all = true;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (tableB[j][i] == false) all = false;
            }
        }

        if (all) {
            cout << k + 1 << endl;
            exit(0);
        }

    }

}

int main() {

    part1();

    part2();

    return 0;
}