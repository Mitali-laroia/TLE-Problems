#include<bits/stdc++.h>
#define int long long
using namespace std;

static bool comp(pair<int,int> &a, pair<int,int> &b){
    return a.first+a.second < b.first+b.second;
}

void solve(){
    int n,c;
    cin>>n>>c;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second = i;
    } 
    sort(a.begin(), a.end(), comp);
    int ans = 0;

    for(int i=0;i<n;i++){
        int cost = a[i].second+1+a[i].first;
        if(cost<=c){
            c-=cost;
            ans++;
        }
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