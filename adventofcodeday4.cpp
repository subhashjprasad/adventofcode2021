#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int cnt = 0;
int mx = 0;

struct Board {

    vector<int> numbers;
    bool won = false;

    Board(vector<int> values, int start) {

        for (int i = start; i < start + 25; i++) {
            numbers.push_back(values[i]);
        }

    }

    void mark(int draw) {

        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == draw) numbers[i] = -1;
        }

        winCheck(draw);
    }

    void winCheck(int val) {

        for (int i = 0; i < 5; i++) {
            if (numbers[i] + numbers[i + 5] + numbers[i + 10] + numbers[i + 15] + numbers[i + 20] == -5) win(val);
        }

        for (int i = 0; i < 25; i += 5) {
            if (numbers[i] + numbers[i + 1] + numbers[i + 2] + numbers[i + 3] + numbers[i + 4] == -5) win(val);
        }
    }

    void win(int val) {

        int sum = 0;

        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] != -1) sum += numbers[i];
        }

        cout << sum * val << endl;
        exit(0);
    }

    void mark2(int draw) {

        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == draw) numbers[i] = -1;
        }

        winCheck2(draw);
    }

    void winCheck2(int val) {

        for (int i = 0; i < 5; i++) {
            if (numbers[i] + numbers[i + 5] + numbers[i + 10] + numbers[i + 15] + numbers[i + 20] == -5) win2(val);
        }

        for (int i = 0; i < 25; i += 5) {
            if (numbers[i] + numbers[i + 1] + numbers[i + 2] + numbers[i + 3] + numbers[i + 4] == -5) win2(val);
        }
    }

    void win2(int val) {

        int sum = 0;

        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] != -1) sum += numbers[i];
        }

        if (won == false) {

            won = true;

            cnt++;

            if (cnt >= mx) {
                cout << sum * val << endl;
                exit(0);
            }
        }
    }

};

void part1() {

    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday4input.txt");

    vector<int> nums;

    string x = "";

    for (int i = 0; i < 99; i++) {
        getline(inFile, x, ',');
        nums.push_back(stoi(x));
    }

    inFile >> x;
    nums.push_back(stoi(x));

    vector<int> values;

    int y;

    while (inFile >> y) {
        values.push_back(y);
    }

    vector<Board> boards;

    for (int i = 0; i < values.size(); i += 25) {
        Board b{values, i};
        boards.push_back(b); 
    } 

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < boards.size(); j++) {
            boards[j].mark(nums[i]);
        }
    }

}

void part2() {
    
    ifstream inFile;

    inFile.open("C:\\Users\\Subhash\\c++\\textfiles\\adventofcodeday4input.txt");

    vector<int> nums;

    string x = "";

    for (int i = 0; i < 99; i++) {
        getline(inFile, x, ',');
        nums.push_back(stoi(x));
    }

    inFile >> x;
    nums.push_back(stoi(x));

    vector<int> values;

    int y;

    while (inFile >> y) {
        values.push_back(y);
    }

    vector<Board> boards;

    for (int i = 0; i < values.size(); i += 25) {
        Board b{values, i};
        boards.push_back(b); 
    } 

    cnt = 0;
    mx = boards.size();

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < boards.size(); j++) {
            boards[j].mark2(nums[i]);
        }
    }

}

int main() {

    part1();

    part2();

    return 0;

}