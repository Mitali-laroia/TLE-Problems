#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(string s,ll n,ll k){
    vector<ll> zeros;
    for(ll i=0;i<n;i++){
        if(s[i]=='0') zeros.push_back(i+1);
    }
    ll ans = LONG_LONG_MAX;
    ll left=0,right=k,mid=0;
    while(right<zeros.size()){
        while(max(zeros[mid]-zeros[left],zeros[right]-zeros[mid])>max(zeros[mid+1]-zeros[left],zeros[right]-zeros[mid+1])){
            mid++;
        }
        ans = min(ans,max(zeros[mid]-zeros[left],zeros[right]-zeros[mid]));
        left++;
        right++;
    }
    return ans;
}

int main(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    cout<<solve(s,n,k)<<endl;
    return 0;
}