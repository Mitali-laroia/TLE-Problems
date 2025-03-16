#include <bits/stdc++.h>
using namespace std;

int asker(int l, int r){
    int ans;
    cout << "? " << (r - l + 1) << " ";
    for(int i = l; i <= r; i++){
        cout << i << " ";
    }
    cout << endl;
    cout.flush();
    cin >> ans;
    return ans;
}

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    p[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    int l = 1, r = n, ans = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(asker(l, mid) > p[mid] - p[l - 1]){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout<<"! "<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}