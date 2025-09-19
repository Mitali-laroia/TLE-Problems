#include<bits/stdc++.h>
#define int long long int
using namespace std;

int fact[250001];
void factorial(int n, int m){
    fact[0] = 1, fact[1] = 1;
    for(int i=2;i<=n;i++) fact[i] = ((fact[i-1]%m)*(i%m))%m;
}

void solve(){
    int n, m;
    cin>>n>>m;
    int totalSumOfSegments = 0;
    factorial(n,m);

    for(int i=n;i>=1;i--){
        int framedSegments = ((i%m));
        framedSegments = ((framedSegments%m) * (fact[n-i+1]%m))%m;
        framedSegments = ((framedSegments%m) * (fact[i-1]%m))%m;
        framedSegments = ((framedSegments%m)*(i%m))%m;
        totalSumOfSegments = ((totalSumOfSegments%m) + (framedSegments%m))%m;
    }

    cout<<totalSumOfSegments<<"\n";
}

signed main(){
    solve();
    return 0;
}