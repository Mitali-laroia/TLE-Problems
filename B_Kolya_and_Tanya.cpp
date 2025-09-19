#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll mod = 1e9+7;

long long binomial_exp(long long a, long long b) {
        long long res = 1;
        while(b>0) {
            if(b&1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }

void solve(){
    ll n;
    cin>>n;
    ll ans = (binomial_exp(3,3*n) - binomial_exp(7,n)+mod)%mod;
    cout<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}