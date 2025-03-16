#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(vector<vector<ll>> v, ll n, ll mid){
    ll minPos = 0, maxPos = 0;
    for(ll i=0;i<n;i++){
        minPos = max(minPos-mid,v[i][0]);
        maxPos = min(maxPos+mid,v[i][1]);
        if(minPos>maxPos) return false;
    }
    return minPos<=maxPos;
}

ll solve(vector<vector<ll>> v, ll n){
    ll low = 0, high = 1e18;
    ll ans = -1;
    while(low<=high){
        ll mid = (low+high)/2;
        if(check(v,n,mid)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> v(n,vector<ll>(2));
        for(ll i=0;i<n;i++){
            cin>>v[i][0]>>v[i][1];
        }
        cout<<solve(v,n)<<endl;
    }
    return 0;
}