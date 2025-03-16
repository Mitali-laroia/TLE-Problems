#include<bits/stdc++.h>
#define ll long long int
using namespace std;

static bool compare(vector<ll> a1, vector<ll> a2){
    return a1[2]<a2[2];
}

bool check(vector<vector<ll>> battery,ll n,ll k, ll mid){
    ll excess = 0, cost = 0;
    for(int i=0; i<n; i++){
        if(battery[i][0]<mid) continue;
        excess+=battery[i][0]-mid;
        cost+=(battery[i][0]-mid)*battery[i][1];
    }

    for(int i=0; i<n && cost<=k&& excess; i++){
        if(battery[i][0]>=mid) continue;
        ll num=min(excess,mid-battery[i][0]);
        excess-=num;
        cost+=num*battery[i][2];
    }
    if(cost<=k&&!excess)
        return 1;
    return 0;
}

ll solve(vector<vector<ll>> battery,ll n,ll k){
    ll ans;
    ll low = 0,high =0;
    sort(battery.begin(),battery.end(),compare);
    for(ll i=0;i<n;i++){
        high = max(high,battery[i][0]);
        low+=battery[i][0];
    } 
    low=(low+n-1)/n;
    while(low<=high){
        ll mid = (low+high)/2;
        if(check(battery,n,k,mid)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int main(){
    ll n, k;
    cin>>n>>k;
    vector<vector<ll>> battery(n,vector<ll>(3));
    for(ll i=0;i<n;i++){
        cin>>battery[i][0]>>battery[i][1]>>battery[i][2];
    }
    cout<<solve(battery,n,k)<<endl;
    return 0;
}