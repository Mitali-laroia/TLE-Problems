#include<bits/stdc++.h>
using namespace std;

void solve(){
    double m,n;
    cin>>m>>n;
    double ans = m;
    for(double i=m-1;i>=1;i--){
        double sub = pow(i/m,n);
        ans-=sub;
    }
    cout<<setprecision(12)<<fixed<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}