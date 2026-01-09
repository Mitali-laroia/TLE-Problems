#include<bits/stdc++.h>
#define int long long
using namespace std;

static bool comp(pair<int,int> &a, pair<int,int> &b){
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    if(n == 1){
        cout<<1<<"\n";
        return;
    }
    int ans = 2;
    int lastX = v[0].first;

    for(int i=1;i<n-1;i++){
        if(v[i].first - v[i].second > lastX) {
            lastX = v[i].first;
            ans++;
        } else if(v[i].first + v[i].second < v[i+1].first){
            ans++;
            lastX = v[i].first + v[i].second;
        } else{
            lastX = v[i].first;
        }
    }
    cout<<ans<<"\n";
}

signed main() {
    solve();
    return 0;
}