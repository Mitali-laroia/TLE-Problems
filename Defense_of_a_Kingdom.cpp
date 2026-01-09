#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int w, h, n;
    cin>>w>>h>>n;
    vector<int> x(n+2), y(n+2);
    x[0] = 0;
    y[0] = 0;
    for(int i=0;i<n;i++){
        cin>>x[i+1]>>y[i+1];
    }
    x[n+1] = (w+1);
    y[n+1] = (h+1);

    if(n==0){
        cout<<w*h<<"\n";
        return;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int lastX = x[0], lastY = y[0];
    vector<int> partX, partY;

    for(int i=1;i<x.size();i++){
        int diff = x[i]-x[i-1]-1;
        if(diff>0){
            partX.push_back(diff);
        }
    }

    for(int i=1;i<y.size();i++){
        int diff = y[i]-y[i-1]-1;
        if(diff>0){
             partY.push_back(diff);
        }
    }

    int ans = 0;
    for(int i=0; i<partY.size(); i++){
        for(int j=0; j<partX.size(); j++){
            ans = max(ans, partX[j]*partY[i]);
        }
    }
    cout<<ans<<"\n";
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}