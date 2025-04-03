#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5+1;
int spf[N];

void seive(){
    for(int i=2;i<N;i++) spf[i] = i;
    for(int i=2;i<N;i++){
        for(int j=2*i;j<N;j+=i) spf[j] = i;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> freq(n+1,0), mx(n+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<=n) freq[x]++;
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            mx[j]+=freq[i];
        }
    }

    cout<<*max_element(mx.begin(),mx.end())<<"\n";
    
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}