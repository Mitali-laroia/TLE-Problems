#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n);
    for (auto &i : nums){
        cin >> i;
    }

    ll maxsum = LONG_MIN;
    vector<ll> pre(n + 1);

    for (int i = 1; i <= n; i++){
        pre[i] += pre[i - 1] + nums[i - 1];
    }

    multiset<ll> ms;
    for (int i = a; i <= n; i++){
        if (i > b){
            ms.erase(ms.find(pre[i - b - 1]));
        }
        ms.insert(pre[i - a]);
        maxsum = max(maxsum, pre[i] - *ms.begin());
    }

    cout << maxsum << endl;
    return 0;
}