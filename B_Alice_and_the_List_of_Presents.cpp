#include<bits/stdc++.h>
#define int long long 
using namespace std;

int mod = 1e9+7;
int binomial_expo(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

void solve(){
    int n, m;
    cin>>n>>m;
    int per_kind = binomial_expo(2,m) - 1;
    int all_boxes = binomial_expo(per_kind,n)%mod;
    cout<<all_boxes<<"\n";
}

signed main(){
    solve();
    return 0;
}