#include <bits/stdc++.h>
using namespace std;

long long ans;

long long cal_ans(int a, int b, int c){
    return 1ll*(a-b)*(a-b) + 1ll*(b-c)*(b-c) + 1ll*(c-a)*(c-a);
}

void solve(vector<int> &a, vector<int> &b, vector<int> &c){
    for(int p1 = 0; p1 < a.size(); p1++){
        auto it2 = lower_bound(b.begin(), b.end(), a[p1]);
        auto it3 = upper_bound(c.begin(), c.end(), a[p1]);

        if(it2 == b.end()) continue;
        if(it3 != c.begin()) it3--;

        ans = min(ans, cal_ans(a[p1], *it2, *it3));
    }
    // O(n log n)
}

int main(){
    int t; cin>>t;
    while(t--){
        int nr, ng, nb; cin>>nr>>ng>>nb;

        vector<int> red(nr, 0);
        vector<int> green(ng, 0);
        vector<int> blue(nb, 0);

        for(int i = 0; i<nr; i++){
            cin>>red[i];
        }
        for(int i = 0; i<ng; i++){
            cin>>green[i];
        }
        for(int i = 0; i<nb; i++){
            cin>>blue[i];
        }

        sort(red.begin(), red.end());
        sort(green.begin(), green.end());
        sort(blue.begin(), blue.end());
        // O(nlogn)

        ans = cal_ans(red[0], blue[0], green[0]);

        solve(red, green, blue);
        solve(red, blue, green);
        solve(green, red, blue);
        solve(green, blue, red);
        solve(blue, red, green);
        solve(blue, green, red);
        // O(6*n log n) = O(n log n)

        cout<<ans<<endl;
    }
    // TC = O(nlogn)
    // SC = (O(n))
    // where n is max of nr, nb and ng
    return 0;
}
