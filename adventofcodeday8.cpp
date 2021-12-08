#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday8input.txt");

    vector<string> v;

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    int count = 0;

    for (int i = 0; i < v.size(); i++) {
        if ((i % 15 == 11) || (i % 15 == 12) || (i % 15 == 13) || (i % 15 == 14)) {
            if ((v[i].length() == 2) || (v[i].length() == 3) || (v[i].length() == 4) || (v[i].length() == 7)) count++;
        }
    }

    cout << count << endl;

}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday8input.txt");

    vector<string> v;

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    string realA, realB, realC, realD, realE, realF, realG;
    string one, seven, four, eight;
    int counter = 0;
    int output = 0;
    int sum = 0;

    for (int i = 0; i < v.size(); i += 15) {

        for (int j = i; j < i + 10; j++) {
            if (v[j].length() == 2) one = v[j];
            else if (v[j].length() == 3) seven = v[j];
            else if (v[j].length() == 4) four = v[j];
            else if (v[j].length() == 7) eight = v[j];
        }

        counter = 0;

        for (int j = i; j < i + 10; j++) {
            if (v[j].find(one[0]) != string::npos) counter++;
        }

        if (counter == 9) {
            realF = one.substr(0, 1);
            realC = one.substr(1, 1);
        }
        else {
            realF = one.substr(1, 1);
            realC = one.substr(0, 1);
        }

        for (int j = 0; j < 3; j++) {
            if ((seven.substr(j, 1) != realF) && (seven.substr(j, 1) != realC)) realA = seven.substr(j, 1);
        }

        for (int k = 0; k < 7; k++) {

            counter = 0;

            for (int j = i; j < i + 10; j++) {
                if (v[j].find(eight[k]) != string::npos) counter++;
            }

            if (counter == 6) realB = eight[k];
            else if (counter == 4) realE = eight[k];
        }

        for (int j = 0; j < 4; j++) {
            if ((four.substr(j, 1) != realF) && (four.substr(j, 1) != realC) && (four.substr(j, 1) != realB)) realD = four.substr(j, 1);
        }

        for (int j = 0; j < 7; j++) {
            if ((eight.substr(j, 1) != realA) && (eight.substr(j, 1) != realB) && (eight.substr(j, 1) != realC) && (eight.substr(j, 1) != realD) && (eight.substr(j, 1) != realE) && (eight.substr(j, 1) != realF)) realG = eight.substr(j, 1);
        }

        output = 0;

        for (int j = i + 11; j < i + 15; j++) {
            if (v[j].length() == 2) output = output * 10 + 1;
            else if (v[j].length() == 3) output = output * 10 + 7;
            else if (v[j].length() == 4) output = output * 10 + 4;
            else if (v[j].length() == 7) output = output * 10 + 8;
            else if ((v[j].length() == 6) && (v[j].find(realC[0]) != string::npos) && (v[j].find(realE[0]) != string::npos)) output = output * 10 + 0;
            else if ((v[j].length() == 6) && (v[j].find(realD[0]) != string::npos) && (v[j].find(realE[0]) != string::npos)) output = output * 10 + 6;
            else if ((v[j].length() == 6) && (v[j].find(realC[0]) != string::npos) && (v[j].find(realD[0]) != string::npos)) output = output * 10 + 9;
            else if ((v[j].length() == 5) && (v[j].find(realE[0]) != string::npos)) output = output * 10 + 2;
            else if ((v[j].length() == 5) && (v[j].find(realC[0]) != string::npos) && (v[j].find(realF[0]) != string::npos)) output = output * 10 + 3;
            else output = output * 10 + 5;
        }

        sum += output;

    }

    cout << sum << endl;

}

int main() {

    part1();

    part2();

    return 0;  

}