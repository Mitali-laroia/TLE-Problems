#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n;
    cin>>n;
    ll count = 0;
    if(n%2){
        cout<<0<<"\n";
        return;
    }
    for(ll i = 5; i<=n/2;i*=5){
        count+=(n/(2*i));
    }

    cout<<count<<"\n";
}

int main(){
    solve();
    return 0;
}