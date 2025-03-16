#include<bits/stdc++.h>
using namespace std;

vector<int> ask(int mid, int n){
    vector<int> ans(3,INT_MAX);
    if(mid-1>0){
        cout<<"? "<<mid-1<<endl;
        cin>>ans[0];
    }
    cout<<"? "<<mid<<endl;
    cin>>ans[1];
    if(mid+1<=n){
        cout<<"? "<<mid+1<<endl;
        cin>>ans[2];
    }
    return ans;
}

void solve(int n){
    int low = 1,high = n;
    int ans;

    while(low<=high){
        int mid = (low+high)/2;
        // cout<<"mid: "<<mid<<endl;
        vector<int> val = ask(mid,n); //mid-1,mid,mid+1
        // cout<<val[0]<<":"<<val[1]<<":"<<val[2]<<endl;
        if((val[1]<val[0]) and (val[1]<val[2])){
            ans = mid;
            cout<<"! "<<ans<<endl;
            break;
        }
        else if((val[1]>val[0]) and (val[1]<val[2])){
            high = mid-1;
        }
        else low = mid+1;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    solve(n);
    return 0;
}