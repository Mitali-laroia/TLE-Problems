#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll solve(string s,ll n,ll c){
    // if(c>=n) return 0;
    ll ans = 0;
    ll a=0,b=0;
    ll cur = 0;
    for(ll left=0,right=0;right<n;right++){
        a+=(s[right]=='a');
        b+=(s[right]=='b');
        if(s[right]=='b') cur+=a;
        while(cur>c){
            a-=(s[left]=='a');
            b-=(s[left]=='b');
            if(s[left]=='a') cur-=b;
            left++;
        }
        ans = max(ans,right-left+1);
    }
    return ans;
}

int main(){
    ll n,c;
    cin>>n>>c;
    string s;
    cin>>s;
    cout<<solve(s,n,c)<<endl;
    return 0;
}