#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct RollingHash {
    const int base = 911, mod = 1e9 + 7;
    vector<int> hash, power;
 
    RollingHash(const string &s) {
        int n = s.size();
        hash.resize(n + 1);
        power.resize(n + 1);
        power[0] = 1;
        for (int i = 0; i < n; ++i) {
            hash[i + 1] = (hash[i] * base + s[i]) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
    }
 
    int get(int l, int r) {
        return (hash[r + 1] - hash[l] * power[r - l + 1] % mod + mod) % mod;
    }
};
 
int32_t main() {
    string t;
    cin >> t;
    int n = t.size();
    RollingHash rh(t);
 
    for (int len = 1; len < n; ++len) {
        int start1 = 0, end1 = len - 1;
        int start2 = n - len, end2 = n - 1;
 
        if (end2 <= end1) continue; 
        if (rh.get(start1, end1) == rh.get(start2, end2)) {
    if (len > (n)/2) {
        cout << "YES\n" << t.substr(start1,len) << "\n";
        return 0;
    }
}
 
    }
 
    cout << "NO\n";
    return 0;
}