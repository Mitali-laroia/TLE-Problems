#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll binary_expo(ll a,ll b, ll mod){
    ll res = 1;
    while(b){
        if(b&1) res=res*a; res=res%mod;
        a=a*a;
        a=a%mod;
        b>>=1;
    }
    return res%mod;
}

ll solve(ll a,ll b,ll c){
    ll m = binary_expo(b,c,1e9+6);
    ll ans = binary_expo(a,m,1e9+7);
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<solve(a,b,c)<<"\n";
    }
    return 0;
}