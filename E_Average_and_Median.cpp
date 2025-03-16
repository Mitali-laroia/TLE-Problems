#include<bits/stdc++.h>
using namespace std;

double check(vector<double> transformed_arr, int n, double mid){
    vector<double> dp(n,0);
    dp[0] = transformed_arr[0];
    dp[1] = max(transformed_arr[1],dp[0]+transformed_arr[1]);
    for(int i=2;i<n;i++){
        dp[i] = transformed_arr[i]+max(dp[i-1],dp[i-2]);
    }
    return max(dp[n-1],dp[n-2]);
}

double solve_average(vector<double> a, int n){
    double low = 0, high = 1e9;
    double ans = 0;
    for(int it=0;it<100;it++){
        double mid = (low+high)/2;
        vector<double> transformed_arr(n);
        for(int i=0;i<n;i++){
            transformed_arr[i] = a[i]-mid;
        }
        if(check(transformed_arr,n,mid)>=0){
            ans = mid;
            low = mid+1e-7;
        }
        else high = mid-1e-7;
    }
    return ans;
}

int solve_median(vector<double> a, int n){
    int low = 0, high = 1e9;
    int ans = 0;
    while(low<=high){
        int mid = (low+high)/2;
        vector<double> transformed_arr(n);
        for(int i=0;i<n;i++){
            if(a[i]>=mid) transformed_arr[i] = 1;
            else transformed_arr[i] = -1;
        }
        if(check(transformed_arr,n,mid)>0){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<double> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<setprecision(7)<<fixed<<solve_average(a,n)<<endl;
    cout<<setprecision(7)<<fixed<<solve_median(a,n)<<endl;
    return 0;
}