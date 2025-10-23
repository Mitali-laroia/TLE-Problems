#include<bits/stdc++.h>
#define int long long 
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    vector<int> left(n+1), right(n+1);
    vector<int> max_l(n+1), max_r(n+1);
    for(int i=1;i<=n;i++){
        left[i] = b[i]+i;
    }
    for(int i=1;i<=n;i++){
        right[i] = b[i]-i;
    }

    max_l[1] = LONG_MIN;
    max_r[n] = LONG_MIN;
    for(int i=2;i<=n;i++){
        max_l[i] = max(max_l[i-1], left[i-1]);
    }
    for(int i=n-1;i>=1;i--){
        max_r[i] = max(max_r[i+1], right[i+1]);
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, max_l[i]+max_r[i]+b[i]);
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