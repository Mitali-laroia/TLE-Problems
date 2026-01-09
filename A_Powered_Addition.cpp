#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int max_num = LLONG_MIN, max_diff = 0, max_index = 0, diff = 0;
    vector<int> indices;

    for(int i=0;i<n;i++){
        max_num = max(max_num, a[i]);
        if(i>0){
            if(a[i]<a[i-1]){
                diff=max(max_num-a[i], diff);
            }
        }
    }

    int ans = 0;
    if(diff) ans = log2(diff)+1;
    cout<<ans<<"\n";
}

signed main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}