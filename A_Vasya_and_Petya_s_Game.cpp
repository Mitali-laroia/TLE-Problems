#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3+1;
vector<int> primes,isPrime(N,1);

void seive(){
    for(int i=2;i*i<N;i++){
        if(isPrime[i]){
            for(int j=2*i;j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

void solve(){
    seive();
    int n;
    cin>>n;
    vector<int> req(n+1,0);
    int count = 0;

    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            // cout<<"run for "<<i<<"\n";
            req[i] = 1;
            count++;
            for(int j=i*i;j<=n;j*=i){
                if(req[j]==0){
                    req[j] = 1;
                    count++;
                }
            }
        }
    }

    cout<<count<<"\n";
    for(int i=2;i<=n;i++){
        if(req[i]) cout<<i<<" ";
    }
}

int main(){
    solve();
    return 0;
}