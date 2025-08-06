#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 1e6;
const int P = 1e9+7;
int fact[N+1];
int inv_fact[N+1];

int binomial_exp(int a, int b){
    int res = 1;
    while(b>0){
        if(b&1) res=(res*a)%P;
        a=(a*a)%P;
        b=b>>1;
    }
    return res%P;
}

int inv(int num){
    return binomial_exp(num,P-2);
}

void calculate(){
    fact[0] = 1;
    for(int i=1;i<=N;i++){
        fact[i] = (1LL*fact[i-1]*i)%P;
    }

    inv_fact[N] = inv(fact[N]);
    for(int i=N-1;i>=0;i--){
        inv_fact[i] = (1LL*inv_fact[i+1]*(i+1))%P;
    }
}

void solve(){
    calculate();
    int n;
    cin>>n;
    int ans = 1;
    for(int i=1;i<=n;i++){
        if(i%2) ans=(ans-inv_fact[i]+P)%P;
        else ans=(ans+inv_fact[i])%P;
    }
    ans=(1LL*ans*fact[n])%P;
    cout<<ans<<"\n";
}

signed main(){
    solve();
    return 0;
}