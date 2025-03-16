#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> a,ll n, ll k){
    ll ans = 0;
    multiset<ll> ms;
    ll mx = 0, mn = LONG_LONG_MAX;
    for(ll left=0,right=0;right<n;right++){
        ms.insert(a[right]);
        mn = *ms.begin();
        mx = *(--ms.end());
        while(mx-mn>k){
            ms.erase(ms.find(a[left]));
            mn = *ms.begin();
            mx = *(--ms.end());
            left++;
        }
        ans+=(right-left+1);
    }
    return ans;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    cout<<solve(a,n,k)<<"\n";
    return 0;
}