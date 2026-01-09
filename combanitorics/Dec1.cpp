#include<bits/stdc++.h>
#include<fstream>
using namespace std;

vector<pair<char,int>> loadInput(string filename) {
    vector<pair<char,int>> instructions;
    ifstream file(filename);
    string line;

    while(getline(file, line)) {
        char direction = line[0];
        int distance = stoi(line.substr(1));
        // cout<<distance<<":";
        instructions.emplace_back(direction, distance);
    }

    return instructions;
}

int solve(vector<pair<char, int>> instructions, bool countInCycle = false) {
    int currPos = 50;
    int zeros = 0;
    // cout<<instructions.size()<<endl;

    for(auto it:instructions) {
        pair<char,int> p = it;
        if(p.second >= 100) {
           if(countInCycle) zeros += p.second/100;
           p.second = p.second%100;
        }
        if(p.first == 'L') {
            int nextPos = currPos - p.second;
            if(nextPos<0) {
                if(countInCycle && currPos>0) zeros++;
                nextPos = 100 + nextPos;
            }
            currPos = nextPos;
        } else {
            int nextPos = currPos + p.second;
            if(nextPos>=100) {
                if(countInCycle && nextPos!=100) {
                    zeros++;
                }
                nextPos = nextPos%100;
            }
            currPos = nextPos;
        }
        if(currPos == 0) zeros++;
        }
        return zeros;
}

void partOne() {
    auto instructions =  loadInput("/mnt/c/Users/04042/Documents/tle/combanitorics/input.txt");
    auto result = solve(instructions, true);
    cout<<result<<endl;
}

void partTwo() {
    auto instructions =  loadInput("/mnt/c/Users/04042/Documents/tle/combanitorics/input.txt");
    auto result = solve(instructions, false);
    cout<<result<<endl;
}

int main() {
    partOne();
    partTwo();
    return 0;
}