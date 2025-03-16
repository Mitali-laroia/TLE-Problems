#include<bits/stdc++.h>
using namespace std;

bool check(vector<double> transformed_arr, int n, int k){
    sort(transformed_arr.begin(),transformed_arr.end(),greater<>());
    double sum = 0;
    for(int i=0;i<k;i++){
        sum+=transformed_arr[i];
    }
    return sum>=0;
}

double solve(vector<pair<double,double>> pairs, int n,int k){
    double low = 0, high = 1e9;
    double ans = 0;
    for(int it=0;it<60;it++){
        double mid = (low+high)/2;
        vector<double> transformed_arr(n);
        for(int i=0;i<n;i++){
            transformed_arr[i] = pairs[i].first-mid*pairs[i].second;
        }
        if(check(transformed_arr,n,k)){
            ans = mid;
            low = mid-1e-7;
        }
        else high = mid+1e-7;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<double,double>> pairs(n);
    for(int i=0;i<n;i++){
        cin>>pairs[i].first>>pairs[i].second;
    }
    cout<<setprecision(7)<<fixed<<solve(pairs,n,k)<<endl;
    return 0;
}