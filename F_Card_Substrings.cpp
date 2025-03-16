#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(string s,string t,ll n,ll m){
    vector<ll> freq(26,0);
    for(ll i=0;i<m;i++) freq[t[i]-'a']++;
    ll ans = 0;

    for(ll left=0,right=0;right<n;right++){
        freq[s[right]-'a']--;
        while(*min_element(freq.begin(),freq.end())<0){
            freq[s[left]-'a']++;
            left++;
        }
        // cout<<ans<<"->";
        ans+=(right-left+1);
    }
    return ans;
}

int main(){
    ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    cout<<solve(s,t,n,m)<<endl;
    return 0;
}