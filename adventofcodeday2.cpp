#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday2input.txt");

    vector<string> v;

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    int hpos = 0;
    int depth = 0;

    for (int i = 1; i < v.size(); i += 2) {

        if (v[i - 1] == "forward") hpos += stoi(v[i]);
        else if (v[i - 1] == "down") depth += stoi(v[i]);
        else if (v[i - 1] == "up") depth -= stoi(v[i]);
    }

    cout << hpos * depth << endl;

}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday2input.txt");

    vector<string> v;

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    int hpos = 0;
    int depth = 0;
    int aim = 0;

    for (int i = 1; i < v.size(); i += 2) {

        if (v[i - 1] == "forward") {
            hpos += stoi(v[i]);
            depth += aim * stoi(v[i]);
        } 
        else if (v[i - 1] == "down") aim += stoi(v[i]);
        else if (v[i - 1] == "up") aim -= stoi(v[i]);
    }

    cout << hpos * depth << endl;

}

int main() {

    part1();

    part2();

    return 0;
}