#include<bits/stdc++.h>
using namespace std;

vector<string> loadInput(string filename) {
    vector<string> banks;
    ifstream file(filename);
    string line;

    while(getline(file, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        banks.push_back(line);
    }

    return banks;
}

int bestForBank(string bank) {
    int n = bank.length();

    int largestNum = -1, largestIndex = -1;
    for(int i=0;i<=n-2;i++){
        int num = bank[i]-'0';
        if(num > largestNum) {
            largestNum = num;
            largestIndex = i;
        }
    }

    int secondLargest = -1;
    for(int i=largestIndex+1;i<n;i++) {
        int num = bank[i]-'0';
        if(num > secondLargest) secondLargest = num;
    }

    int ans = largestNum*10+ secondLargest;
    // cout<<ans<<"\n";
    return ans;
}

string bestpart2(string bank){
    int n = bank.size();
    vector<int> st;
    int k = 12;

    for(int i=0;i<n;i++){
        int num = bank[i]-'0';
        while(!st.empty() and st.back() < num and (st.size()+n-i-1)>=k){
            st.pop_back();
        }

        if(st.size()<k){
            st.push_back(num);
        }
    }
    
    while(st.size()>k){
        st.pop_back();
    }

    // cout<<st.size()<<":";

    string ans = "";
    for(int i=0;i<st.size();i++){
        ans+=to_string(st[i]);
    }
    // cout<<ans<<"\n";
    return ans;
}

void partOne(vector<string> banks) {
    int n = banks.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=bestForBank(banks[i]);
    }
    cout<<ans<<"\n";
}

void partTwo(vector<string> banks) {
    int n = banks.size();
    long long ans = 0;
    for(int i=0;i<n;i++){
        string temp = bestpart2(banks[i]);
        ans+=stoll(temp);
    }
    cout<<ans<<"\n";
}

signed main() {
    vector<string> banks = loadInput("/mnt/c/Users/04042/Documents/tle/combanitorics/input.txt");
    partTwo(banks);
    return 0;
}