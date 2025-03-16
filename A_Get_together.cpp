#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(vector<vector<long double>> ppl,int n, long double mid){
    long double minPos = INT_MIN, maxPos = INT_MAX;
    for(int i=0;i<n;i++){
        long double dist = ppl[i][1]*mid;
        minPos = max(minPos, ppl[i][0]-dist);
        maxPos = min(maxPos,ppl[i][0]+dist);
        if(minPos>maxPos) return false;
    }
    return minPos<=maxPos;
}

long double solve(vector<vector<long double>> ppl, int n){
    long double low = 0, high = 1e9;
    long double ans = 0;
    for(int i=0;i<60;i++){
        long double mid = (low+high)/2;
        if(check(ppl,n,mid)){
            ans = mid;
            high = mid;
        }
        else low = mid; 
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    vector<vector<long double>> ppl(n,vector<long double>(2));
    //0: coord, 1: speed
    for(ll i=0;i<n;i++){
        cin>>ppl[i][0]>>ppl[i][1];
    }
    cout<<setprecision(15)<<fixed<<solve(ppl,n)<<endl;
}