#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p.begin(), p.end());

    int median = 0;
    if(n%2){
        median = p[n/2];
    }
    else {
        median = (p[n/2] + p[(n/2)-1])/2;
    }
    int cost = 0;
    for(int i=0;i<n;i++){
        cost+=abs(median-p[i]);
    }
    cout<<cost<<"\n";
}

signed main(){
    solve();
    return 0;
}