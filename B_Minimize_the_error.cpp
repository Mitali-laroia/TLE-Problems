#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k1,k2;
    cin>>n>>k1>>k2;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int temp = 0;
    int k = k1+k2;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(abs(a[i]-b[i]));
        // temp+=(a[i]-b[i])*(a[i]-b[i]);
    }

    // if(temp==0){
    //     cout<<temp<<"\n";
    //     return;
    // } 

    while(k>0){
        int t = pq.top();
        if(t==0) break;
        pq.pop();
        pq.push(t-1);
        k--;
    }

    int ans = 0;
    while(!pq.empty()){
        int t = pq.top();
        pq.pop();
        ans+=t*t;
    }

    if(k%2) ans++;
    cout<<ans<<"\n";
}

signed main(){
    solve();
    return 0;
}