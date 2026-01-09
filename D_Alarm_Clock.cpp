#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    set<int> st;
    int ans = 0;

    for(int i=0;i<n;i++){
        while(!st.empty() && *st.begin()<a[i]-m+1){
            st.erase(st.begin());
        }
        if(st.size()<k-1) st.insert(a[i]);
        else ans++;
    }
    cout<<ans<<"\n";
}

signed main() {
    solve();
    return 0;
}