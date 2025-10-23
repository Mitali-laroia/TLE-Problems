#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> b(n);
    int maxvalue = -1;
    int sum = 0;

    for(int i=0;i<n;i++){
        cin>>b[i];
        sum+=b[i];
        maxvalue = max(maxvalue, b[i]);
    }
    int ans = max(maxvalue*2, sum);
    cout<<ans<<"\n";
}

signed main(){
    solve();
    return 0;
}