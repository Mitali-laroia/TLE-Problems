 
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#ifdef ONLINE_JUDGE
#define debug(...) 47
#else
#include "debug.h"
#endif
#define int long long
#define double long double
#define endl '\n'
#define inf LLONG_MAX >> 2
#define coutb(CONDITION) cout << (CONDITION ? "YES" : "NO") << endl;
#define gcd(num1, num2) (__gcd(num1, num2))
#define lcm(num1, num2) ((num1) * (num2) / __gcd((num1), (num2)))
#define clz(num) (__builtin_clzll(num))
#define ctz(num) (__builtin_ctzll(num))
#define popct(num) (__builtin_popcountll(num))
template <typename T>
istream &operator>>(istream &in, vector<T> &vec)
{
    for (auto &elem : vec)
        in >> elem;
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &vec)
{
    for (const auto &elem : vec)
        out << elem << " ";
    return out;
}
const int mod = 1000000007;
 
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    int maxE = *max_element(v.begin(), v.end());
    vector<int> freq(4e6);
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }
    int carry = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        freq[i] += carry;
        carry = freq[i] / 2;
        freq[i] %= 2;
    }
    cout << accumulate(freq.begin(), freq.end(), 0ll) << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    while (tc--)
    {
        solve();
    }
    return 0;
}