#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> a,ll n,ll k){
    ll ans = 0;
    map<ll,ll> mp;

    for(ll left=0,right=0;right<n;right++){
        mp[a[right]]++;
        while(mp.size()>k){
            mp[a[left]]--;
            if(mp[a[left]]<=0) mp.erase(a[left]);
            left++;
        }
        ans+=(right-left+1);
    }
    return ans;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(a,n,k)<<endl;
    return 0;
}