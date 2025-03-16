#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> a,ll n,ll s){
    ll sum = 0;
    ll ans = 0;
    for(ll left=0,right=0;right<n;right++){
        sum+=a[right];
        while(sum>s){
            sum-=a[left];
            left++;
        }
        ll length = right-left+1;
        ans+=(length*(length+1))/2;
    }
    return ans;
}

int main(){
    ll n,s;
    cin>>n>>s;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    cout<<solve(a,n,s)<<endl;
    return 0;
}