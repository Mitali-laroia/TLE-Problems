#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(ll label, ll mid, vector<ll> pre){
    return pre[mid]>=label;
}

void solve(ll label,vector<ll> pre,ll n){
    ll low = 0, high = n-1;
    ll ans = -1;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(check(label,mid,pre)){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    cout<<ans+1<<endl;
}

int main(){
    ll n,m;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>m;
    // for(int i=0;i<m;i++) cin>>q[i];
    vector<ll> pre(n,0);
    pre[0] = v[0];
    for(int i=1;i<n;i++) pre[i]=pre[i-1]+v[i];
    for(int i=0;i<m;i++){
        int key;
        cin>>key;
        solve(key,pre,n);
    }
    return 0;
}