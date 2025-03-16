#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> a,ll n,ll t){
    ll ans = 0;
    ll time = 0;
    for(ll left=0,right=0;right<n;right++){
        time+=a[right];
        while(time>t){
            time-=a[left];
            left++;
        }
        ans = max(ans,right-left+1);
    }
    return ans;
}

int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    cout<<solve(a,n,t)<<"\n";
    return 0;
}