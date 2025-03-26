#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];
    ll ans = 0;
    for(int i=0;i<n;i++) ans = __gcd(ans,a[i]-a[0]);
    for(int i=0;i<m;i++) cout<<abs(__gcd(ans,a[0]+b[i]))<<" ";
}

int main(){
    solve();
    return 0;
}