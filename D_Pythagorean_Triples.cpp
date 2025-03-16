#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> v;
void pre(){
    ll n=1e5;
    v.push_back(0);
    // c=b+1, a^2=2*b+1
    for(ll i=3;i<n;i+=2){
        ll a = i;
        ll b = (a*a)/2;
        ll c = (a*a)/2+1;
        if((a*a+b*b)==c*c and a*a==(b+c)){
            v.push_back(c);
            // cout<<c<<":";
        }
    }
    // cout<<endl;
}

void tell(ll ans){
    cout<<ans<<endl;
    return;
}

int main(){
    ll t;
    cin>>t;
    pre();
    while(t--){
        ll n;
        cin>>n;
        auto ans = upper_bound(v.begin(),v.end(),n)-v.begin();
        cout<<ans-1<<endl;
    }
    return 0;
}