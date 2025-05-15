#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int ans = n;
    vector<int> gap;
    for(int i=1;i<n;i++){
        gap.push_back(a[i]-a[i-1]-1);
    }

    sort(gap.begin(), gap.end());
    for(int i=0;i<n-k;i++){
        ans+=gap[i];
    }

    cout<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}