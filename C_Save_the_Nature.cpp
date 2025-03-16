#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check(int prefix, vector<int>&arr, int x, int a, int y, int b, int k)
{
    int LCM = a / gcd(a, b) * b;

    int aCount = prefix / a - prefix / LCM;
    int bCount = prefix / b - prefix / LCM;
    int lcmCount = prefix / LCM;

    int i = 0, money = 0;

    while(lcmCount--) money += arr[i++] / 100 * (x + y);
    while(aCount--) money += arr[i++] / 100 * (x);
    while(bCount--) money += arr[i++] / 100 * (y);

    return money >= k;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt; cin >> tt;

    while(tt--)
    {
        int n, k, x, a, y, b; cin >> n;

        vector<int>arr(n);
        for(auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end(), greater());

        cin >> x >> a >> y >> b >> k;

        if(x < y) swap(x, y), swap(a, b);

        int left = 1, right = n, answer = -1;

        while(left <= right)
        {
            int mid = (left + right) / 2;

            if(check(mid, arr, x, a, y, b, k))
            {
                answer = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        cout << answer << "\n";
    }
}