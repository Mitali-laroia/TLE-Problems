#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        if(n%i!=i-1){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main(){
    solve();
    return 0;
}