#include<bits/stdc++.h>
#define int long long
using namespace std;

const int P = 998244353;
const int N = 2e5;
int fact[N+1];

int binomial_expo(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (res*a)%P;
        a=(a*a)%P;
        b>>=1;
    }
    return res;
}

int inv(int num){
    return binomial_expo(num,P-2);
}

void calculate(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<=N;i++) fact[i] = ((i%P)*(fact[i-1])%P)%P;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    } 
    sort(a.rbegin(), a.rend());

    int ans = 1;
    // cout<<a[0]<<" ";
    if(mp[a[0]]>1) ans = fact[n]%P;
    else{
        ans = ((fact[n]%P) - (fact[n]%P*inv(mp[a[0]-1]+1)%P)%P+P)%P;
    }
    cout<<ans<<"\n";
}

signed main(){
    calculate();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}