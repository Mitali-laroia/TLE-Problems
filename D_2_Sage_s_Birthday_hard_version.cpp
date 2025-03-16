#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> a, int n, int mid){
    int ok = 1;
    int j = n-1;
    for(int i=mid-1;i>=0;i--,j--){
        ok = ok&(a[i]<a[j] and a[i]<a[j-1]);
    }
    return ok;
}

void solve(vector<int> a,int n){
    sort(a.begin(),a.end());
    int low = 1, high = (n+1)/2-1;
    int ans = 0;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(a,n,mid)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
    vector<int> res(n);
    int i=n-1, j=ans-1;
    if(ans==0){
        res = a;
    }
    else{
        for(int k=0;k<n;k++){
            if(k%2==0 or j==-1) res[k] = a[i--];
            else res[k] = a[j--];
        }
    }
    
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    solve(a,n);
    return 0;
}