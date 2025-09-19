#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int x =0, y=0;
    map<int,int> mp;
    mp[0]=1;
    int ans = 0;

    for(int i=0;i<n;i++){
        if(s[i]=='0') x++;
        else y++;
        int z = min(x,y);
        x-=z, y-=z;
        ans+=(mp[x-y]*(n-i));
        mp[x-y]+=(i+2);
        mp[x-y]%=mod;
        ans%=mod;
    }

    cout<<ans<<"\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}