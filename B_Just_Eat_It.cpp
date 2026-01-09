#include<bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
    int n;
    cin>>n;
    int sum = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    vector<int> minus_index;
    for(int i=0;i<n;i++){
        if(a[i]<=0) minus_index.push_back(i);
    }

    vector<int> prefix(n);
    prefix[0] = a[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+a[i];
    }

    for(int i=0;i<minus_index.size();i++){
        int sum_before = 0, sum_after = 0;
        if(minus_index[i]>0) sum_before = prefix[minus_index[i]-1];
        if(minus_index[i]<n-1) sum_after = sum - prefix[minus_index[i]];
        if(sum_before >= sum or sum_after >= sum){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}