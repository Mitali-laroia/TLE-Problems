#include<bits/stdc++.h>
using namespace std;

bool check(int low, int high){
    vector<int> query;
    cout<<"? "<<low<<" "<<high<<endl;
    int count = high-low+1;
    while(count--){
        int num;
        cin>>num;
        query.push_back(num);
    } 

    count = 0;
    for(auto num:query){
        if(num>=low and num<=high) count++;
    }

    return count&1;
}

int solve(int n){
    int low = 1, high = n;
    int ans = -1;

    while(low<=high){
        int mid = (low+high)/2;
        if(check(low,mid)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = solve(n);
        cout<<"! "<<ans<<endl;
    }
    return 0;
}