#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+1;
int spf[N], isOn[N], primes[N];

// Optimized Sieve of Eratosthenes
void sieve() {
    for (ll i = 0; i < N; i++) spf[i] = i;
    
    for (ll i = 2; i * i < N; i++) {
        if (spf[i] == i) {  // If i is a prime
            for (ll j = i * i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

// Prime Factorization using Smallest Prime Factor (SPF) array
vector<int> primeFactorization(int num) {
    vector<int> ans;
    if (num < 1) return ans;  // Prevents invalid input processing

    while (num > 1) {
        if (num >= N || spf[num] == 0) break;  // Avoid division by zero
        int p = spf[num];
        ans.push_back(p);
        while (num % p == 0) num /= p;
    }
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        char ch;
        int num;
        cin >> ch >> num;

        // if (num <= 0 || num >= N) {  // Check input range
        //     cout << "Invalid input\n";
        //     continue;
        // }

        vector<int> factors = primeFactorization(num);
        // if (factors.empty()) {
        //     cout << "Invalid number\n";
        //     continue;
        // }

        if (ch == '+') {
            if (isOn[num] == 0) {
                int collision = 0;
                for (auto &p : factors) {
                    if (primes[p]) collision = primes[p];
                }
                if (collision) cout << "Conflict with " << collision << "\n";
                else {
                    cout << "Success\n";
                    isOn[num] = 1;
                    for (auto &p : factors) primes[p] = num;
                }
            } else cout << "Already on\n";
        } 
        else if (ch == '-') {
            if (isOn[num]) {
                cout << "Success\n";
                for (auto &p : factors) primes[p] = 0;
                isOn[num] = 0;
            } else cout << "Already off\n";
        }
    }
}

int main() {
    sieve();  // Precompute primes only once
    memset(isOn, 0, sizeof(isOn));
    memset(primes, 0, sizeof(primes));
    solve();
    return 0;
}
