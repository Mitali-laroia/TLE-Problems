#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    char maxPossibleChar = 'a';
    char notPossibleChar = 'a';

    for(int i=0;i<n;i++){
        if(s[i]-'a'>k){
            notPossibleChar = s[i];
            break;
        }
        if(s[i]>maxPossibleChar) maxPossibleChar = s[i];
    }

    int opCountPossible = maxPossibleChar - 'a';
    int leftOpCoubt = k - opCountPossible;
    char to = notPossibleChar - leftOpCoubt;

    for(char c = notPossibleChar; c>to; c--){
        for(char &e: s){
            if(e==c){
                e--;
            }
        }
    }

    for(char &ch:s){
        if(ch<=maxPossibleChar) ch = 'a';
    }

    cout<<s<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}