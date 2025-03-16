#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> a,ll n,ll r){
    ll ans = 0;
    for(ll left=0,right=0;left<n;left++){
        while(right<n and a[right]-a[left]<=r) right++;
        if(right==n) break;
        if(right<=n-1) ans+=(n-right);
    }
    return ans;
}

int main(){
    ll n,r;
    cin>>n>>r;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    cout<<solve(a,n,r)<<"\n";
    return 0;
}