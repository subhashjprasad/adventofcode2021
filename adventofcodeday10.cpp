#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday10input.txt");

    vector<string> v;

    string x;

    while (getline(inFile, x)) {
        v.push_back(x);
    }

    string str;
    vector<string> lastOpen;
    vector<string> errors;

    for (int k = 0; k < v.size(); k++) {

        str = v[k];
        lastOpen.clear();
        lastOpen.push_back("");

        for (int i = 0; i < str.length(); i++) {

            if ((str.substr(i, 1) == "(") || (str.substr(i, 1) == "[") || (str.substr(i, 1) == "{") || (str.substr(i, 1) == "<")) {
                lastOpen.push_back(str.substr(i, 1));
            } else if ((str.substr(i, 1) == ")") && (lastOpen[lastOpen.size() - 1] == "(")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else if ((str.substr(i, 1) == "]") && (lastOpen[lastOpen.size() - 1] == "[")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else if ((str.substr(i, 1) == "}") && (lastOpen[lastOpen.size() - 1] == "{")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else if ((str.substr(i, 1) == ">") && (lastOpen[lastOpen.size() - 1] == "<")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else {
                errors.push_back(str.substr(i, 1));
                break;
            }
        }

    }

    int errorScore = 0;

    for (int i = 0; i < errors.size(); i++) {
        if (errors[i] == ")") errorScore += 3;
        else if (errors[i] == "]") errorScore += 57;
        else if (errors[i] == "}") errorScore += 1197;
        else if (errors[i] == ">") errorScore += 25137;
    }

    cout << errorScore << endl;
}

void part2() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday10input.txt");

    vector<string> v;

    string x;

    while (getline(inFile, x)) {
        v.push_back(x);
    }

    string str;
    vector<string> lastOpen;
    vector<string> errors;

    for (int k = 0; k < v.size(); k++) {

        str = v[k];
        lastOpen.clear();
        lastOpen.push_back("");

        for (int i = 0; i < str.length(); i++) {

            if ((str.substr(i, 1) == "(") || (str.substr(i, 1) == "[") || (str.substr(i, 1) == "{") || (str.substr(i, 1) == "<")) {
                lastOpen.push_back(str.substr(i, 1));
            } else if ((str.substr(i, 1) == ")") && (lastOpen[lastOpen.size() - 1] == "(")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else if ((str.substr(i, 1) == "]") && (lastOpen[lastOpen.size() - 1] == "[")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else if ((str.substr(i, 1) == "}") && (lastOpen[lastOpen.size() - 1] == "{")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else if ((str.substr(i, 1) == ">") && (lastOpen[lastOpen.size() - 1] == "<")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else {
                v.erase(v.begin() + k);
                k--;
                break;
            }
        }

    }

    string completion = "";
    vector<string> completionLines;

    for (int k = 0; k < v.size(); k++) {

        str = v[k];
        lastOpen.clear();
        lastOpen.push_back("");
        completion = "";

        for (int i = 0; i < str.length(); i++) {

            if ((str.substr(i, 1) == "(") || (str.substr(i, 1) == "[") || (str.substr(i, 1) == "{") || (str.substr(i, 1) == "<")) {
                lastOpen.push_back(str.substr(i, 1));
            } else if ((str.substr(i, 1) == ")") && (lastOpen[lastOpen.size() - 1] == "(")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else if ((str.substr(i, 1) == "]") && (lastOpen[lastOpen.size() - 1] == "[")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else if ((str.substr(i, 1) == "}") && (lastOpen[lastOpen.size() - 1] == "{")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else if ((str.substr(i, 1) == ">") && (lastOpen[lastOpen.size() - 1] == "<")) {
                lastOpen.erase(lastOpen.end() - 1);
            } else {
                v.erase(v.begin() + k);
                k--;
                break;
            }

        }

        for (int j = lastOpen.size() - 1; j > 0; j--) {
                if (lastOpen[j] == "(") completion += ")";
                else if (lastOpen[j] == "[") completion += "]";
                else if (lastOpen[j] == "{") completion += "}";
                else if (lastOpen[j] == "<") completion += ">";
            }

        completionLines.push_back(completion);

    }

    unsigned long long score = 0;
    vector<unsigned long long> scores;

    for (int i = 0; i < completionLines.size(); i++) {

        score = 0;
        str = completionLines[i];

        for (int j = 0; j < str.length(); j++) {
            if (str.substr(j, 1) == ")") score = score * 5 + 1;
            else if (str.substr(j, 1) == "]") score = score * 5 + 2;
            else if (str.substr(j, 1) == "}") score = score * 5 + 3;
            else if (str.substr(j, 1) == ">") score = score * 5 + 4;
        }

        scores.push_back(score);

    }

    sort(scores.begin(), scores.end());

    cout << scores.size() << endl;

    cout << scores[scores.size() / 2] << endl;
    
}

int main() {

    part1();

    part2();

    return 0;

}