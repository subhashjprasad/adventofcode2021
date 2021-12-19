#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday14input.txt");

    string x;

    string poly;

    inFile >> poly;

    vector<string> v;

    while (inFile >> x) {
        v.push_back(x);
    }

    for (int k = 0; k < 10; k++) {

        string temp = "";

        for (int i = 0; i < poly.length(); i++) {

            if (i == poly.length() - 1) temp += poly.substr(i, 1);
            else {
                string seg = poly.substr(i, 2);

                bool replaced = false;

                for (int j = 0; j < v.size(); j += 3) {
                    if (seg == v[j]) {
                        temp += seg[0] + v[j + 2];
                        replaced = true;
                    }
                }

                if (replaced == false) temp += seg[0];
            } 
            
        }

        poly = temp;
    }

    int occur[26];

    for (int i = 0; i < 26; i++) {
        occur[i] = 0;
    }

    for (int i = 0; i < poly.length(); i++) {
        occur[(int)poly[i] - 65]++;
    }

    int max = 0;
    int min = INT_MAX;

    for (int i = 0; i < 26; i++) {
        if (occur[i] > max) max = occur[i];
        if ((occur[i] < min) && (occur[i] != 0)) min = occur[i];
    }

    cout << max - min << endl;

}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday14input.txt");

    string x;

    string poly;

    inFile >> poly;

    vector<string> v;

    while (inFile >> x) {
        v.push_back(x);
    }

    unsigned long long table[26][26];

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            table[i][j] = 0;
        }
    }

    for (int i = 0; i < poly.length() - 1; i++) {
        table[(int)(poly[i]) - 65][(int)(poly[i + 1]) - 65]++;
    }

    for (int k = 0; k < 40; k++) {

        unsigned long long temp[26][26];

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                temp[i][j] = table[i][j];
            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                string dou;
                dou.push_back((char)(i + 65));
                dou.push_back((char)(j + 65));

                for (int n = 0; n < v.size(); n += 3) {

                    if (dou == v[n]) {

                        for (unsigned long long h = 0; h < table[i][j]; h++) {
                            temp[i][j]--;
                            temp[i][(int)((v[n + 2])[0]) - 65]++;
                            temp[(int)((v[n + 2])[0]) - 65][j]++;
                        }
                    }

                }

            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                table[i][j] = temp[i][j];
            }
        }

    }

    unsigned long long occur[26];

    for (int i = 0; i < 26; i++) {
        occur[i] = 0;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            occur[i] += table[i][j];
            occur[j] += table[i][j];
        }
    }

    for (int i = 0; i < 26; i++) {
        if ((i == (int)(poly[0]) - 65) || ((i == (int)(poly[poly.length() - 1]) - 65))) occur[i] = (occur[i] + 1) / 2;
        else occur[i] = occur[i] / 2;
    }

    unsigned long long max = 0;
    unsigned long long min = ULLONG_MAX;

    for (int i = 0; i < 26; i++) {
        if (occur[i] > max) max = occur[i];
        if ((occur[i] < min) && (occur[i] != 0)) min = occur[i];
    }

    cout << max - min << endl;

}

int main() {

    part1();

    part2();

    return 0;

}