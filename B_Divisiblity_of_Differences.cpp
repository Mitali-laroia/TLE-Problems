#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> a(n);
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]%m].push_back(a[i]);
    } 

    for(auto it:mp){
        if(it.second.size()>=k){
            cout<<"Yes\n";
            for(int i=0;i<k;i++) cout<<it.second[i]<<" ";
            return;
        }
    }

    cout<<"No\n";
}

int main(){
    solve();
    return 0;
}