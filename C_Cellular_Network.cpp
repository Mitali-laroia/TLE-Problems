#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            // ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            ans = mid;
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int solve(vector<int> city, vector<int> tower, int n ,int m){
    vector<int> upper(n,INT_MAX), lower(n,INT_MAX);
    for(int i=0;i<n;i++){
        int itr = upperBound(tower,city[i],m);
        if(itr!=m){
            upper[i] = tower[itr];
        }
        int itr2 = lowerBound(tower,m,city[i]);
        if(itr2!=m){
            lower[i] = tower[itr2];
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int dist1 = INT_MAX, dist2 = INT_MAX;
        // cout<<lower[i]<<":"<<upper[i]<<endl;
        if(lower[i]!=INT_MAX) dist1 = abs(lower[i]-city[i]);
        if(upper[i]!=INT_MAX) dist2 = abs(upper[i]-city[i]);
        // cout<<dist1<<":"<<dist2<<endl;
        int dist = min(dist1,dist2);
        ans = max(ans,dist);
    }

    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> city(n),tower(m);
    for(int i=0;i<n;i++) cin>>city[i];
    for(int i=0;i<m;i++) cin>>tower[i];
    cout<<solve(city,tower,n,m);
    return 0;
}