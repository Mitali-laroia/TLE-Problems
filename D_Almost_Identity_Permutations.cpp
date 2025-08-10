#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    ll ans = 1;
    ll fact[5];
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<5;i++){
        fact[i] = i*fact[i-1];
    }

    for(int i=2;i<=k;i++){
        ll result = fact[i];
        ll denom = 1;
        int parity = -1;

        for(int j=1;j<=i;j++){
            denom*=j;
            result+=parity*(fact[i]/denom);
            parity*=-1;
        }

        ll num = 1;
        for(int j=n;j>n-i;j--){
            num*=j;
        }

        ll ncr = num/fact[i];
        ans+=result*ncr;
    }

    cout<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}