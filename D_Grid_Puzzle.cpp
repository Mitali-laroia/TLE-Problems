#include<bits/stdc++.h>
#define int long long
using namespace std;
static const long long INF = 3e18;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(4, INF));
    dp[0][0] = 0;

    for(int i=1;i<=n;i++){
        if (a[i - 1] > 0) {
            dp[i][0] = dp[i - 1][0] + 1;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
        if (i == 1) {
            if (a[i - 1] <= 2) {
                dp[i][1] = 1; 
            }
            continue;
        }
        if (a[i - 1] >= 5) {
            continue;
        }
        dp[i][0] = min(dp[i][0], dp[i - 1][3]);
        dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);
        dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);
        dp[i][3] = min(dp[i][3], dp[i - 1][0] + 2);
        if (a[i - 1] <= 2) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
        }
    }
    cout<<dp[n][0]<<"\n";
}

signed main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}