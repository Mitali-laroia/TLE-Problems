#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int> a,int n){
    int ans = 0;
    for(int i=0;i<n/2;i++){
        int sub = abs(a[i]-a[n-1-i]);
        ans = __gcd(ans,sub);
        // cout<<ans<<" ";
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<solve(a,n)<<"\n";
    }
    return 0;
}