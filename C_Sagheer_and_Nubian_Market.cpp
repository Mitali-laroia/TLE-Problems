#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

pair<ll,ll> calculate(vector<ll> cost, ll k,ll s, ll n){
    vector<ll> v(n,0);
    for(ll i=0;i<n;i++){
        v[i] = cost[i]+k*(i+1);
    }
    sort(v.begin(),v.end());
    ll total_cost = 0, items = 0;
    ll i=0;
    for(ll i=0;i<k;i++){
        total_cost+=v[i];
    }

    return {total_cost,k};
}

int check(vector<ll> cost, ll k, ll s, ll n){
    ll total_cost = 0;
    for(ll i=0;i<n;i++){
        total_cost+= cost[i]+(i+1)*k;
    }
    // cout<<total_cost<<endl;
    return total_cost;
}

pair<ll,ll> solve(vector<ll> cost,ll n,ll s){
    ll low = 1, high = n;
    ll total_cost = 0, total_item = 0;

    while(low<=high){
        ll mid = (low+high)/2;
        // cout<<mid<<" ";
        ll temp_cost = calculate(cost,mid,s,n).first;
        if(temp_cost<=s){
            // pair<ll,ll> p = calculate(cost,mid,s,n);
            // cout<<mid<<":"<<p.first<<":"<<p.second<<" ";
            // if(p.second>total_item){
            //     total_cost = p.first;
            //     total_item = p.second;
            // }
            // else if(p.second==total_item){
            //     total_cost = min(total_cost,p.first);
            // }
            total_cost = temp_cost;
            total_item = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return {total_cost,total_item};
}

int main(){
    ll n,s;
    cin>>n>>s;
    vector<ll> cost(n);
    for(ll i=0;i<n;i++){
        cin>>cost[i];
    }
    // sort(cost.begin(),cost.end());
    pair<ll,ll> ans = solve(cost,n,s);
    cout<<ans.second<<" "<<ans.first;
    return 0;
}