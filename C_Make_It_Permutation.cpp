#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, c, d;
    cin>>n>>c>>d;
    set<int> s;
    vector<int> a;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        s.insert(num);
    }

    int ans = 0;
    ans+=(n-s.size())*c;

    for(int i: s){
        a.push_back(i);
    }
    n = a.size();
    int cost = LLONG_MAX;
    for(int i=0;i<n;i++){
        int x = a[i]-(i+1);
        int val1 = max(0LL, x)*d;
        int val2 = (n-(i+1))*c;
        cost = min(cost, val1+val2);
    }
    cost = min(cost, n*c+d);
    cout<<ans+cost<<"\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}