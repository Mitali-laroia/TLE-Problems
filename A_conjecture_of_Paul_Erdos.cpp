#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e7+1;
vector<bool> isPrime(N, true), isType(N, false);
vector<ll> dp(N, 0);

// Optimized Sieve of Eratosthenes
void sieve() {
    isPrime[0] = isPrime[1] = false;
    
    for (ll i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j < N; j += i) {  // Start from i*i
                isPrime[j] = false;
            }
        }
    }

    // Precompute isType values
    for (ll i = 0; i * i < N; i++) {
        for (ll j = 0; j * j * j * j < N; j++) {
            ll num = (i * i) + (j * j * j * j);
            if (num < N) isType[num] = true;
            else break;
        }
    }

    // Compute dp array
    for (ll i = 0; i < N; i++) {
        if (isPrime[i] && isType[i]) dp[i] = 1;
    }
    
    for (ll i = 1; i < N; i++) {  // Start from i=1 to avoid dp[-1]
        dp[i] += dp[i - 1];
    }
}

void solve(ll n) {
    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}
