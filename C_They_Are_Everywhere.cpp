#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(string s,ll n){
    map<char,ll> mp,mp_test;
    for(char ch:s) mp[ch]++;
    ll count = mp.size();
    ll ans = LONG_LONG_MAX;
    for(ll left=0,right=0;right<n;right++){
        mp_test[s[right]]++;
        while(left<=right and mp_test.size()>=count){
            ans = min(ans,right-left+1);
            mp_test[s[left]]--;
            if(mp_test[s[left]]<=0) mp_test.erase(s[left]);
            left++;
        }
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    cout<<solve(s,n)<<endl;
    return 0;
}