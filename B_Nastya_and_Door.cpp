#include<bits/stdc++.h>
using namespace std;

pair<int,int> solve(vector<int> a,int n,int k){
    multiset<int> st;
    pair<int,int> ans = {1,1};
    vector<int> is_peak(n,0);
    for(int i=1;i<n-1;i++){
        if(a[i]>a[i-1] and a[i]>a[i+1]) is_peak[i] = 1;
    }
    vector<int> pre(n,0);
    pre[0] = 0;
    for(int i=1;i<n;i++) pre[i] = pre[i-1]+is_peak[i];

    int peaks = 0;
    for(int i=0;i<n;i++){
        // if(is_peak[i]) st.insert(a[i]);
        // if(i>=k){
        //     if(!st.empty() and is_peak[i-k]) st.erase(st.find(a[i-k]));
        // }
        if(i>=k-1){
            int temp = pre[i-1]-(i-k+1>=0 ? pre[i-k+1] : 0);
            if(temp>peaks){
                peaks = temp;
                ans = {peaks+1,i+2-k};
            }
        }
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        pair<int,int> ans;
        ans = solve(a,n,k);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}
