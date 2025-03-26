#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 200001;
ll spf[N];
vector<ll> primes[N];

ll binpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

void seive(){
    for(ll i=1;i<N;i++) spf[i] = i;
    for(ll i=2;i<N;i++){
        for(ll j=2*i;j<N;j+=i){
            if(spf[j]==j) spf[j] = i;
        }
    }
}

void solve(){
    seive();
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        ll x = a[i];
        while(x>1){
            ll p = spf[x];
            ll count = 0;
            while(x%p==0){
                count++;
                x/=p;
            }
            primes[p].push_back(count);
        }
    }

    // for(int i=0;i<n;i++) cout<<primes[i].size()<<" ";

    long long LCM = 1;
    for(ll i=0;i<N;i++){
        sort(primes[i].begin(),primes[i].end());
        if(primes[i].size()<n-1) continue;
        else{
            if(primes[i].size()==n) LCM*=binpow(i,primes[i][1]);
            else LCM*=binpow(i,primes[i][0]);
        }
    }
    cout<<LCM<<"\n";
}

int main(){
    solve();
    return 0;
}