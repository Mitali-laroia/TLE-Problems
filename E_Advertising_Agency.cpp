#include<bits/stdc++.h>
using namespace std;

static const int N = 1e3;
static const int P = 1e9+7;
long long fact[N+1], inv_fact[N+1];

long long binomial_exp(long long a, long long b) {
    long long res = 1;
    while(b>0) {
        if(b&1) res = res*a%P;
        a = a*a%P;
        b >>= 1;
    }
    return res;
}

long long inv(long long num) {
    return binomial_exp(num, P-2);
}

void calculate() {
    fact[0] = 1;
    for(int i=1; i<=N; i++) {
        fact[i] = (fact[i-1]*i)%P;
    } 
    inv_fact[N] = inv(fact[N]);
    for(int i=N-1; i>=0; i--) {
        inv_fact[i] = (inv_fact[i+1]*(i+1))%P;
    }
}

long long ncr(int n, int r) {
    if (r < 0 || r > n) return 0; 
    return fact[n]*inv_fact[n-r]%P*inv_fact[r]%P;
}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        mp[num]++;
    }
    for(auto it:mp){
        a.push_back(it.first);
    }

    sort(a.rbegin(), a.rend());
    int index = a.size()-1;
    long long ans = 1;

    for(int i=0;i<a.size();i++){
        int count = mp[a[i]];
        if(count>k) ans=(ans*ncr(count,k))%P;
        k-=count;
        if(k<=0) break;
    }
    
    cout<<ans<<"\n";
}

int main(){
    calculate();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}