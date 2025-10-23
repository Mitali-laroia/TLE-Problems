#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> power = {0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

void solve(){
    int n;
    cin>>n;
    int i=1;
    int odd = 0, even = 0;
    odd = power[n];
    int remain_half = (n/2)-1;
    while(i<=remain_half){
        odd+=power[i];
        i++;
    } 

    while(i<n){
        even+=power[i];
        i++;
    }

    int ans = abs(odd-even);
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