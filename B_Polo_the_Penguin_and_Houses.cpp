#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
int precalc[] = {0, 1, 2, 9, 64, 625, 7776, 117649, 2097152};

int binomial_expo(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

void solve(){
    int n,k;
    cin>>n>>k;
    int ans = ((precalc[k]%mod)*(binomial_expo(n-k,n-k)%mod))%mod;
    cout<<ans<<"\n";
}

signed main(){
    solve();
    return 0;
}