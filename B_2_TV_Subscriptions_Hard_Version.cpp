#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<ll> a,ll n,ll d,ll k){
    int ans = INT_MAX;
    ll temp = 0;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if(i>=d){
            mp[a[i-d]]--;
            if(mp[a[i-d]]<=0) mp.erase(a[i-d]);
        }
        if(i>=d-1){
            int size = mp.size();
            ans = min(ans,size);
        }
    }
    return ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k,d;
        cin>>n>>k>>d;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        cout<<solve(a,n,d,k)<<"\n";
    }
    return 0;
}