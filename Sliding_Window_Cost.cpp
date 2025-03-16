#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int n, int k){
    multiset<long long> lo,hi;
    vector<long long> ans;
    long long left_sum=0, right_sum = 0;
    auto balance = [&](){
        if (lo.size() > hi.size() + 1)
        {
            right_sum += *lo.rbegin();
            left_sum -= *lo.rbegin();
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }
        if (hi.size() > lo.size())
        {
            right_sum -= *hi.begin();
            left_sum += *hi.begin();
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    };


    for(int i=0;i<n;i++){
        if (lo.empty() || nums[i] <= *lo.rbegin()){
            lo.insert(nums[i]);
            left_sum += nums[i];
        }
        else{
            hi.insert(nums[i]);
            right_sum += nums[i];
        }
 
        balance();

        if (i >= k){
            int out = nums[i - k];
            if (out <= *lo.rbegin()){
                left_sum -= out;
                lo.erase(lo.find(out));
            }
            else{
                right_sum -= out;
                hi.erase(hi.find(out));
            }
            balance();
        }


        if(i>=k-1){
            long long median = *lo.rbegin();
            long long val = ((median * lo.size()) - left_sum) + (right_sum - (hi.size() * median));
            ans.push_back(val);
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