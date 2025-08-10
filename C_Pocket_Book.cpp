#include<bits/stdc++.h>
using namespace std;

void solve(){
    int mod = 1e9+7;
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    int ans = 1;
    for(int i=0;i<m;i++){
        unordered_set<char> s;
        for(int j=0;j<n;j++){
            s.insert(v[j][i]);
        }
        ans = ((ans%mod)*(s.size()%mod))%mod;
    }

    cout<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}