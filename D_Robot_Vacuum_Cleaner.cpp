#include<bits/stdc++.h>
#define int long long
using namespace std;

int func(string a){
    int res = 0, count =0;
    for(int i=0;i<a.length();i++){
        if(a[i]=='s') count++;
        else res+=count;
    }
    return res;
}

static bool comp(string &a, string &b){
    if(func(a+b)>func(b+a)) return true;
    return false;
}

void solve(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s.begin(), s.end(), comp);
    string res = "";
    for(int i=0;i<n;i++) res+=s[i];
    // cout<<res<<"\n";
    int ans = func(res);
    cout<<ans<<"\n";
}

signed main(){
    solve();
    return 0;
}