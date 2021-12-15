#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<string> v;
int paths = 0;

void search(string center, string visited) {

    for (int i = 0; i < v.size(); i++) {

        if (v[i].substr(0, center.length()) == center) {

            if (islower((v[i].substr(v[i].find("-") + 1, v[i].length() - v[i].find("-")))[0])) {

                if ((v[i].substr(v[i].find("-") + 1, v[i].length() - v[i].find("-"))) == "end") {

                    paths++;

                } else if (visited.find((v[i].substr(v[i].find("-") + 1, v[i].length() - v[i].find("-")))) == string::npos) {

                    search((v[i].substr(v[i].find("-") + 1, v[i].length() - v[i].find("-"))), visited + "," + v[i].substr(v[i].find("-") + 1, v[i].length() - v[i].find("-")));

                }
            } else {

                search((v[i].substr(v[i].find("-") + 1, v[i].length() - v[i].find("-"))), visited);
            }
        }
    }

}

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday12input.txt");

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    search("start", "start");

    cout << paths << endl;
}

int main() {

    part1();

    return 0;
}