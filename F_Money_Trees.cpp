#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int>  a(n), h(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> h[i];

    ll i = 0, j = 0;
    ll ans = 0;
    ll weight = 0;

    while (j < n){
        if (j > 0 and h[j - 1] % h[j]){
            i = j;
            weight = 0;
        }
        weight += a[j];
        while (weight > k and i <= j){
            weight -= a[i];
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}