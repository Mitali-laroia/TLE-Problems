#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(vector<int> ropes, ll n, ll k, long double mid){
    ll parts = 0;
    for(ll i=0;i<n;i++){
        parts+=(ropes[i]/mid);
    }
    return parts>=k;
}

long double solve(vector<int> ropes, ll n, ll k){
    long double low = 0, high = 1e7;
    // for(ll i=0;i<n;i++) high = max(high, ropes[i]);
    long double ans = 0;
    for(int i=0;i<50;i++){
        long double mid = (low+high)/2;
        // cout<<mid<<" ";
        if(check(ropes,n,k,mid)){
            // cout<<ans<<" ";
            ans = mid;
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return ans;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vector<int> ropes(n);
    for(ll i=0;i<n;i++) cin>>ropes[i];
    // cout<<setprecision(7)<<fixed;
    // sort(ropes.begin(),ropes.end(),greater<>());
    cout<<setprecision(7)<<fixed<<solve(ropes,n,k)<<endl;
    return 0;
}