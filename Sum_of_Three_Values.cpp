#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(vector<pair<ll,ll>> a,ll n, ll sum){
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        ll first = i;
        ll left = i+1, right = n-1;
        while(left<right){
            ll temp = (a[first].first+a[left].first+a[right].first);
            if(temp==sum){
                vector<int> ans(3);
                ans[0] = a[first].second;
                ans[1] = a[left].second;
                ans[2] = a[right].second;
                sort(ans.begin(),ans.end());
                cout<<ans[0]+1<<" "<<ans[1]+1<<" "<<ans[2]+1<<endl;
                return;
            }
            else if(temp<sum) left++;
            else right--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main(){
    ll n,sum;
    cin>>n>>sum;
    vector<pair<ll,ll>> a(n);
    for(ll i=0;i<n;i++){
        int num;
        cin>>num;
        a[i] = {num,i};
    }
    solve(a,n,sum);
    return 0;
}