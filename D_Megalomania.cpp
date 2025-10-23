#include<bits/stdc++.h>
using namespace std;

static bool comp(pair<int,int> &a, pair<int,int> &b){
    if(a.second == b.second){
        return a.first>b.first;
    }
    return a.second<b.second;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end(), comp);

    int max = v[n-1].second;
    int index = 0;
    for(int i=0;i<n;i++){
        index+=v[i].first;
        if(index>v[i].second){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main(){
    solve();
    return 0;
}