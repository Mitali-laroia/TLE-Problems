#include<bits/stdc++.h>
using namespace std;

void extractRange(string range, vector<string> &result) {
    const auto from = stol(range.substr(0, range.find('-')));
    const auto to = stol(range.substr(range.find('-')+1));
    for(auto i=from; i<=to; i++){
        result.push_back(to_string(i));
    }
}

vector<string> loadInput(string filename) {
    vector<string> result;
    ifstream file(filename);
    string line;

    getline(file, line);
    size_t pos = 0;

    while((pos = line.find(',')) != std::string::npos) {
        auto range = line.substr(0, pos);
        extractRange(range, result);
        line.erase(0, pos+1);
    }

    extractRange(line, result);
    return result;
}

void solve(vector<string> ranges) {
    int n = ranges.size();
    long long int ans = 0;
    for(int i=0;i<n;i++){
        if(ranges[i].length()%2 == 0){
            int len = ranges[i].length();
            string firstHalf = ranges[i].substr(0,len/2);
            string secondHalf = ranges[i].substr(len/2);
            if(firstHalf == secondHalf) ans+=stoll(ranges[i]);
        }
    }
    cout<<ans;
}

bool hasRepeatingPatternBruteForce(const std::string& s) {
    int n = s.length();
    if (n <= 1) {
        return false;
    }

    for (int len = 1; len <= n / 2; ++len) {
        if (n % len == 0) { 
            std::string pattern = s.substr(0, len); 

            bool isRepeating = true;
            for (int i = len; i < n; i += len) {
                if (s.substr(i, len) != pattern) {
                    isRepeating = false;
                    break;
                }
            }

            if (isRepeating) {
                return true; 
            }
        }
    }

    return false; 
}

void solvepart2(vector<string> ranges) {
    int n = ranges.size();
    long long int ans = 0;
    for(int i=0;i<n;i++){
        if(hasRepeatingPatternBruteForce(ranges[i])) ans+=stoll(ranges[i]);
    }
    cout<<ans;
}
 
int main(){
    vector<string> result = loadInput("/mnt/c/Users/04042/Documents/tle/combanitorics/input.txt");
    solvepart2(result);
    return 0;
}