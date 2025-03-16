#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll upperBound(vector<ll> &arr, ll x, ll n) {
    ll low = 0, high = n - 1;
    ll ans = n;

    while (low <= high) {
        ll mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

ll solve(vector<ll> v, ll n){
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll num = v[i];
        ll index = upperBound(v,2*num,n);
        ll pairs = index-i-1;
        // cout<<v[i]<<":"<<pairs<<" ";
        ans+=pairs;
    }
    return ans;
}
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
        v[i] = abs(v[i]);
    }
    sort(v.begin(),v.end());
    cout<<solve(v,n);
    return 0;
}