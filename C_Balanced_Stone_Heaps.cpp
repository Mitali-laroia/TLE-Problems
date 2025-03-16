#include<bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int>& a, int n){
    vector<int> copy(n);
    for (int i = 0; i < n; i++){
        copy[i] = a[i];
    }
    
    for (int i = n - 1; i >= 2; i--){
        if (copy[i] < mid) return false;
        int d = min(a[i], copy[i] - mid) / 3;
        copy[i - 1] += d ;
        copy[i - 2] += 2 * d;
    }
    return (copy[0] >= mid && copy[1] >= mid);
}

int solve(vector<int> h,int n){
    int low = 1, high = 1e9, ans = 0;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(mid,h,n)){
            ans = mid;
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
        vector<int> h(n);
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        cout<<solve(h,n)<<endl;
    }
    return 0;
}