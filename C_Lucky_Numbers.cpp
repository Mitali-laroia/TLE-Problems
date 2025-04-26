#include<bits/stdc++.h>
#define int long long
using namespace std;

int binomial_exp(int a,int b){
    int res = 1;
    while(b>0){
        if(b&1) res*=a;
        a=a*a;
        b>>=1;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    int ans = binomial_exp(2,n+1)-2;
    cout<<ans<<"\n";
}

signed main(){
    solve();
    return 0;
}