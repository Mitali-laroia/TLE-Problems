#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> weights,vector<ll> cost, ll w,ll n){
    ll weight = 0;
    ll temp_cost = 0;
    ll ans = 0;
    for(ll left=0,right=0;right<n;right++){
        weight+=weights[right];
        temp_cost+=cost[right];
        while(weight>w){
            weight-=weights[left];
            temp_cost-=cost[left];
            left++;
        }
        ans = max(ans,temp_cost);
    }
    return ans;
}

int main(){
    ll n,w;
    cin>>n>>w;
    vector<ll> weights(n),cost(n);
    for(ll i=0;i<n;i++){
        cin>>weights[i];
    }
    for(ll i=0;i<n;i++){
        cin>>cost[i];
    }
    cout<<solve(weights,cost,w,n)<<endl;
    return 0;
}