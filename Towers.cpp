#include<bits/stdc++.h>
#define int long long
using namespace std;

static bool comp(pair<int,int> &a, pair<int,int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int ans = 0;
    multiset<int> topElements;
    for (int i = 0; i < n; i++) {
        auto it = topElements.upper_bound(v[i]);
        if (it == topElements.end()) {
            ans++;
            topElements.insert(v[i]);
        }
        else {
            topElements.erase(it);
            topElements.insert(v[i]);
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    solve();
    return 0;
}