#include<bits/stdc++.h>
#define int long long
using namespace std;

static bool comp(pair<int,int> &a, pair<int,int> &b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    return a.first < b.first;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> movies(n);
    for(int i=0;i<n;i++) cin>>movies[i].first>>movies[i].second;
    sort(movies.begin(), movies.end(), comp);

    int ans = 0;
    multiset<int> end_times;
    for(int i=0;i<k;i++) end_times.insert(-1);

    for(int i=0;i<n;i++){
        auto it = end_times.upper_bound(movies[i].first);
        if(it == begin(end_times)) continue;

        end_times.erase(--it);
        end_times.insert(movies[i].second);
        ans++;
    }

    cout<<ans<<"\n";
}

signed main(){
    solve();
    return 0;
}