#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int n, int k){
    multiset<long long> lo,hi;
    auto balance = [&](){
        if(lo.size()>hi.size()+1){
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }
        else if(lo.size()<hi.size()){
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    };

    vector<long long> ans;

    for(int i=0;i<n;i++){
        if(lo.empty() or nums[i]<=*lo.rbegin()) lo.insert(nums[i]);
        else hi.insert(nums[i]);
        balance();

        if(i>=k){
            if(nums[i-k]<=*lo.rbegin()) lo.erase(lo.find(nums[i-k]));
            else hi.erase(hi.find(nums[i-k]));
            balance();
        }

        if(i>=k-1){
            ans.push_back(*lo.rbegin());
            // else ans.push_back((*lo.rbegin()+*hi.begin())/2);
        }
    }

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    solve(a,n,k);
    return 0;
}