#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,string>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].second;
        cin>>v[i].first;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=abs(i+1-v[i].first);
    }
    cout<<ans<<"\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        // string s;
        // cin>>s;
        solve();
    }
    return 0;
}