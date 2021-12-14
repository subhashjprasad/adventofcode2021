#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int table[1500][1500] = {0};

void flipX(int x) {

    for (int i = 0; i < 1500; i++) {
        for (int j = 0; j < 1500; j++) {
            if (table[j][i] == 1) {
                if (j > x) {
                    table[x - (j - x)][i] = 2;
                    table[j][i] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 1500; i++) {
        for (int j = 0; j < 1500; j++) {
            if (table[j][i] == 2) {
                table[j][i] = 1;
            }
        }
    }
}

void flipY(int y) {

    for (int i = 0; i < 1500; i++) {
        for (int j = 0; j < 1500; j++) {
            if (table[j][i] == 1) {
                if (i > y) {
                    table[j][y - (i - y)] = 2;
                    table[j][i] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 1500; i++) {
        for (int j = 0; j < 1500; j++) {
            if (table[j][i] == 2) {
                table[j][i] = 1;
            }
        }
    }
}

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday13input.txt");

    vector<int> v;
    vector<string> f;

    string x;

    while (inFile >> x) {
        if (x.find(",") != string::npos) {
            v.push_back(stoi(x.substr(0, x.find(","))));
            v.push_back(stoi(x.substr(x.find(",") + 1, x.length() - x.find(","))));
        } else if (x.find("x") != string::npos) {
            f.push_back(x.substr(x.find("x"), x.length() - x.find("x")));
        } else if (x.find("y") != string::npos) {
            f.push_back(x.substr(x.find("y"), x.length() - x.find("y")));
        }
    }
    
    for (int i = 0; i < v.size(); i += 2) {
        table[v[i]][v[i + 1]] = 1;
    }
    
    for (int i = 0; i < 1; i++) {
        if ((f[i])[0] == 'x') flipX(stoi(f[i].substr(f[i].find("=") + 1, f[i].length() - f[i].find("="))));
        else if ((f[i])[0] == 'y') flipY(stoi(f[i].substr(f[i].find("=") + 1, f[i].length() - f[i].find("="))));
    }

    int count = 0;

    for (int i = 0; i < 1500; i++) {
        for (int j = 0; j < 1500; j++) {
            if (table[j][i] == 1) {
                count++;
            }
        }
    }

    cout << count << endl;

}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday13input.txt");

    vector<int> v;
    vector<string> f;

    string x;

    while (inFile >> x) {
        if (x.find(",") != string::npos) {
            v.push_back(stoi(x.substr(0, x.find(","))));
            v.push_back(stoi(x.substr(x.find(",") + 1, x.length() - x.find(","))));
        } else if (x.find("x") != string::npos) {
            f.push_back(x.substr(x.find("x"), x.length() - x.find("x")));
        } else if (x.find("y") != string::npos) {
            f.push_back(x.substr(x.find("y"), x.length() - x.find("y")));
        }
    }
    
    for (int i = 0; i < v.size(); i += 2) {
        table[v[i]][v[i + 1]] = 1;
    }
    
    for (int i = 0; i < 1; i++) {
        if ((f[i])[0] == 'x') flipX(stoi(f[i].substr(f[i].find("=") + 1, f[i].length() - f[i].find("="))));
        else if ((f[i])[0] == 'y') flipY(stoi(f[i].substr(f[i].find("=") + 1, f[i].length() - f[i].find("="))));
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 40; j++) {
            if (table[j][i] == 1) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < 1500; i++) {
        for (int j = 0; j < 1500; j++) {
            if (table[j][i] == 1) {
                cout << j << " " << i << endl;
            }
        }
    }

}

int main() {

    //part1();

    part2();

    return 0;

}