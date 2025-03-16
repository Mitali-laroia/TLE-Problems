#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
bool ok(int operations, vector<int>&a, int maxSum, int sum)
{ 
    if(sum - operations <= maxSum) return true;
 
    for(int i = a.size() - 1; i >= max(1ll, (int)a.size() - operations); i--)
    {
        sum -= a[i];
        int operationsLeft = operations - (a.size() - i);
        int tempSum = sum - a[0] + (a.size() - i + 1) * (a[0] - operationsLeft);
        if(tempSum <= maxSum) return true;
    }
 
    return false;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt; cin >> tt;
 
    while(tt--)
    {
        int n, k; cin >> n >> k;
 
        vector<int>a(n);
        for(auto &i : a) cin >> i;
 
        sort(a.begin(), a.end());
 
        int left = 0, right = 1e10, answer = 1e10;
        int sum = accumulate(a.begin(), a.end(), 0ll);
 
        while(left <= right)
        {
            int mid = (left + right) / 2;
 
            if(ok(mid, a, k, sum))
            {
                answer = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
 
        cout << answer << "\n";
    }
}