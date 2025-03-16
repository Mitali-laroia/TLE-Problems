#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<pair<ll,ll>> friends,ll n,ll d){
    ll ans = 0;
    ll temp = 0;
    for(ll left=0,right=0;right<n;right++){
        temp+=friends[right].second;
        while(friends[right].first-friends[left].first>=d){
            temp-=friends[left].second;
            left++;
        }
        ans = max(ans,temp);
    }
    return ans;
}

int main(){
    ll n,d;
    cin>>n>>d;
    vector<pair<ll,ll>> friends(n);
    for(ll i=0;i<n;i++){
        cin>>friends[i].first>>friends[i].second;
    }
    sort(friends.begin(),friends.end());
    cout<<solve(friends,n,d)<<endl;
    return 0;
}