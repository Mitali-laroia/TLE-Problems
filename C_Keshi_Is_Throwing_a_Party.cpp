#include<bits/stdc++.h>
using namespace std;

//a : richer, b: poorer

bool check(vector<int> v,vector<int> a,vector<int> b, int n, int mid){
    int count = 0;

    for(int i=1;i<=n;i++){
        if((count)<=b[i] and (mid-count-1)<=a[i]) count++;
    }
    // cout<<"the answer is "<<ans<<endl;
    return count>=mid;
}

int solve(vector<int> a,vector<int> b, int n){
    int low = 1, high = n;
    int ans;
    vector<int> v(n);
    for(int i=0;i<n;i++) v[i] = i+1;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(v,a,b,n,mid)){
            ans= mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n+1), b(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
        }
        cout<<solve(a,b,n)<<endl;
    }
    return 0;
}