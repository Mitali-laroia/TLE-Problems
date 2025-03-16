#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(int mid,vector<int> stalls,int n,int c){
    int count = 1;
    int prev = stalls[0];

    for(int i=1;i<n;i++){
        if(stalls[i]-prev>=mid){
            prev = stalls[i];
            count++;
        }
    }

    return count>=c;
}

void solve(vector<int> stalls, int n, int c){
    int low = 1, high = 1e9;
    int ans = -1;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(check(mid,stalls,n,c)){
            ans = mid;
            low = mid;
        }
        else high = mid;
    }
    cout<<ans<<endl;
}

void main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> stalls(n);
        for(int i=0;i<n;i++){
            cin>>stalls[i];
        }
        sort(stalls.begin(),stalls.end());
        solve(stalls,n,s);
    }
}