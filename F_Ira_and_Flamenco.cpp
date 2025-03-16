#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll mod = 1e9+7;
ll mul(ll a, ll b){
    return (a*b)%mod;
}

ll power(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans = mul(ans,a);
        a = mul(a,a);
        b = b>>1;
    }
    return ans;
}

ll divide(ll a, ll b){
    return mul(a,power(b,mod-2));
}

ll solve(vector<ll> a,ll n,ll m){
    ll ans = 0;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++) mp[a[i]]++;
    vector<ll> v;
    for(auto it:mp) v.push_back(it.first);
    sort(v.begin(),v.end());
    ll temp = 1;
    for(ll i=0;i<v.size();i++){
        temp=(temp*mp[v[i]])%mod;
        // cout<<temp<<":";
        if(i>=m){
            temp=divide(temp,mp[v[i-m]]);
        }
        if(i>=m-1){
            if(v[i]-v[i-m+1]<m) ans=(ans+temp)%mod;
            // cout<<v[i]<<":"<<v[i-m+1]<<" ";
        }
    }
    // cout<<endl;
    return ans%mod;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        cout<<solve(a,n,m)<<"\n";
    }
    return 0;
}