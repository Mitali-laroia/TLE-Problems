#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6;
const int P = 1e9+7;
int fact[N+1],inv_fact[N+1];

int binomial_exp(int a,int b){
    int res = 1;
    while(b>0){
        if(b&1) res = res*a%P;
        a = a*a%P;
        b>>=1;
    }
    return res;
}

int inv(int num){
    return binomial_exp(num,P-2);
}

void calculate(){
    fact[0] = 1;
    for(int i=1;i<=N;i++){
        fact[i] = (fact[i-1]*i)%P;
    } 
    inv_fact[N] = inv(fact[N]);
    for(int i=N-1;i>=0;i--){
        inv_fact[i] = (inv_fact[i+1]*(i+1))%P;
    }
}

int ncr(int n,int r){
    return fact[n]*inv_fact[r]%P*inv_fact[n-r]%P;
}

void solve(){
    calculate();
    int n,m;
    cin>>n>>m;
    cout<<ncr(n+m-1,n-1)<<"\n";
}

signed main(){
    solve();
    return 0;
}