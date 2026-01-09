#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    if(a[0]!=1){
        cout<<1<<endl;
        return;
    }

    int minSum = 0, maxSum = 1;
    for(int i=1;i<n;i++){
        int newMinSum = minSum+a[i];
        int newMaxSum = maxSum+a[i];
        if(newMinSum - maxSum > 1){
            break;
        }
        maxSum = max(maxSum, newMaxSum);
    }
    cout<<maxSum+1<<"\n";
}

signed main(){
    solve();
    return 0;
}