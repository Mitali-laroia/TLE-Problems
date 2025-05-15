#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> types(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        types[x]++;
    }
    sort(types.begin(), types.end(), greater<int>());
    int ans = 0;

    for(int i=0;i<=n;i++){
        if(i) types[i] = max(0,min(types[i-1]-1,types[i]));
        ans+=types[i];
    }

    cout<<ans<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}