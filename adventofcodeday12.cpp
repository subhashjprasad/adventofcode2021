#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<string> v;
int paths = 0;

void search(string center, string visited) {

    for (int i = 0; i < v.size(); i++) {

        string before = v[i].substr(0, v[i].find("-"));
        string after = v[i].substr(v[i].find("-") + 1, v[i].length());

        if (before == center) {

            if (islower(after[0])) {

                if (after == "end") {

                    paths++;

                } else if (visited.find(after) == string::npos) {

                    search(after, visited + "," + after);

                }
            } else {

                search(after, visited);
            }
        }

        if (after == center) {

            if (islower(before[0])) {

                if (before == "end") {

                    paths++;

                } else if (visited.find(before) == string::npos) {

                    search(before, visited + "," + before);

                }
            } else {

                search(before, visited);
            }
        }
    }
}

void search2(string center, string visited, string twice) {

    for (int i = 0; i < v.size(); i++) {

        string before = v[i].substr(0, v[i].find("-"));
        string after = v[i].substr(v[i].find("-") + 1, v[i].length());

        if (before == center) {

            if (islower(after[0])) {

                if (after == "end") {

                    if ((twice == "") || (visited.find(twice) != string::npos)) {
                        paths++;
                    }

                } else if (visited.find(after) == string::npos) {

                    search2(after, visited + "," + after, twice);

                    if (twice == "") {
                        search2(after, visited, twice + after);
                    }

                }
            } else {

                search2(after, visited + "," + after, twice);
            }
        }

        if (after == center) {

            if (islower(before[0])) {

                if (before == "end") {

                    if ((twice == "") || (visited.find(twice) != string::npos)) {
                        paths++;
                    }

                } else if (visited.find(before) == string::npos) {

                    search2(before, visited + "," + before, twice);

                    if (twice == "") {
                        search2(before, visited, twice + before);
                    }

                }
            } else {

                search2(before, visited + "," + before, twice);
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

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday12input.txt");

    string x;

    while (inFile >> x) {
        v.push_back(x);
    }

    search2("start", "start", "");

    cout << paths << endl;
}

int main() {

    part1();

    part2();

    return 0;
}
