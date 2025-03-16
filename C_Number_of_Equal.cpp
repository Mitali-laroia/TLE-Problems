#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> a,vector<ll> b,ll n,ll m){
    ll i=0,j=0;
    ll ans = 0;
    while(i<n and j<m){
        if(a[i]==b[j]){
            ll count1=0,count2=0;
            ll temp = a[i];
            while(i<n and a[i]==temp){
                count1++;
                i++;
            }
            while(j<m and b[j]==temp){
                count2++;
                j++;
            }
            ans+=(count1*count2);
        }
        else if(a[i]<b[j]) i++;
        else j++;
    }
    return ans;
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];
    cout<<solve(a,b,n,m)<<endl;
    return 0;
}
