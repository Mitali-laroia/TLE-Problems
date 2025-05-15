#include<bits/stdc++.h>
using namespace std;

bool checkRBS(string s){
    int n = s.length();
    int count = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') count++;
        else count--;
        if(count<0) return false;
    }

    return count==0;
}

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int op = n/2, cl = n/2;
    vector<int> pos;

    for(int i=0;i<n;i++){
        if(s[i]=='(') op--;
        else if(s[i]==')') cl--;
        else pos.push_back(i);
    }

    for(int i=0;i<pos.size();i++){
        if(i<op) s[pos[i]] = '(';
        else s[pos[i]] = ')';
    }

    bool ok = true;
    if(op>0 && cl>0){
        swap(s[pos[op-1]], s[pos[op]]);
        if(checkRBS(s)) ok = false;
    }

    cout<< (ok ? "YES\n" : "NO\n");
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}