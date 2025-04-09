#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll a,b;
    cin>>a>>b;
    if(a>b){
        swap(a,b);
    }
    ll k = 0;
    while(a>0){
        k+=(b/a);
        b%=a;
        swap(a,b);
    }
    cout<<k<<"\n";
}

int main(){
    solve();
    return 0;
}