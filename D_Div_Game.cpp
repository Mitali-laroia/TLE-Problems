#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ll count = 0, moves = 0;
            while(n%i==0){
                count++;
                n/=i;
            }
            while((moves*(moves+1))/2<=count) moves++;
            ans+=(moves-1);
        }
    }
    cout<<ans+(n>1)<<"\n";
}

int main(){
    solve();
    return 0;
}
