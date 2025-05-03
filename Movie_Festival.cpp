#include<bits/stdc++.h>
using namespace std;

static bool comp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> segments(n);
    for(int i=0;i<n;i++){
        cin>>segments[i].first>>segments[i].second;
    }
    sort(segments.begin(), segments.end(), comp);
    pair<int,int> last_segment = {INT_MIN, INT_MIN};
    int ans = 0;

    for(int i=0;i<n;i++){
        if(segments[i].first>=last_segment.second){
            ans++;
            last_segment = segments[i];
        }
    }

    cout<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}