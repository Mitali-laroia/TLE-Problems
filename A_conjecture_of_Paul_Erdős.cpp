#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+1;
int isPrime[N] = {1}, isType[N] = {0}, dp[N] = {0};

void seive(){
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<N;i++){
        for(int j=2*i;j<N;j++){
            isPrime[j] = 0;
        }
    }
    for(int i=0;i*i<N;i++){
        for(int j=1;(i*i+j*j*j*j)<N;j++){
            isType[i*i+j*j*j*j] = 1;
        }
    }
    for(int i=0;i<N;i++) if(isPrime[i] and isType[i]) dp[i] = 1;
    for(int i=0;i<N;i++) dp[i]+=dp[i-1];
}

void solve(int n){
    int ans = 0;
    cout<<dp[n]<<"\n";
}

int main(){
    seive();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}