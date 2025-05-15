#include<bits/stdc++.h>
#define int long long
using namespace std;

int MOD = 998244353;
const int N = 3e5;

int fact[N+1], inv_fact[N+1];

int binomal(long long a, long long b){
    long long res = 1;
    while(b > 0){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return (int)res;
}

int inv(int num){
    return binomal(num, MOD - 2);
}

void calculate(){
    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    inv_fact[N] = inv(fact[N]);
    for(int i = N - 1; i >= 0; i--){
        inv_fact[i] = (1LL * inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

int ncr(int n, int r){
    // cout<<fact[n]<<":"<<inv_fact[n-r]<<":"<<inv_fact[r]<<"\n";
    return fact[n]*inv_fact[n-r]%MOD*inv_fact[r]%MOD;
}

void solve(){
    int n;
    cin>>n;
    int ans = 1;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i+=3){
        int count = 0;
        int mxWeight = max({a[i]+a[i+1], a[i+1]+a[i+2], a[i+2]+a[i]});
        if((a[i]+a[i+1])==mxWeight) count++;
        if((a[i+1]+a[i+2])==mxWeight) count++;
        if((a[i]+a[i+2])==mxWeight) count++;
        ans = (ans*count)%MOD;
    }

    ans = (ans*ncr(n/3,n/6))%MOD;
    cout<<ans<<"\n";
}

signed main(){
    calculate();
    solve();
    return 0;
}