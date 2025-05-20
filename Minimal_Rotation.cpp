#include <bits/stdc++.h>
using namespace std;

struct RollingHash {
    const int base = 911, mod = 1e9+7;
    vector<int> hash, power;

    RollingHash(const string &s){
        int n = s.size();
        hash.resize(n+1);
        power.resize(n+1);
        power[0] = 1;
        for(int i = 0; i < n; i++){
            hash[i+1] = (1LL * hash[i] * base + s[i]) % mod;
            power[i+1] = (1LL * power[i] * base) % mod;
        }
    }

    int get(int l, int r){
        return (hash[r+1] - 1LL * hash[l] * power[r-l+1] % mod + mod) % mod;
    }
};

void solve(){
    string s;
    cin >> s;
    s += s;
    int n = s.size() / 2;
    RollingHash rh(s);
    int k = 0;

    for(int i = 1; i < n; i++){
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(rh.get(i, i + mid) == rh.get(k, k + mid)){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(low < n && s[i + low] < s[k + low]){
            k = i;
        }
    }
    cout << s.substr(k, n) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
