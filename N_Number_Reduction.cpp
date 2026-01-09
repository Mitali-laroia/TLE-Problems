#include<bits/stdc++.h>
// #define int long long
using namespace std;

void solve(){
    string s, t;
    cin>>s;
    int n = s.size();
    int k;
    cin>>k;
    deque<int> nums[10];
    for(int i=0;i<n;i++) nums[s[i]-'0'].push_back(i);

    for(int i=0;i<n;i++){
        int currIndex = n, newIndex = n;
        for(int j=0;j<10;j++){
            if(nums[j].size()) currIndex = min(currIndex, nums[j].front());
        }

        for(int j = (i==0); j<10; j++){
            if(nums[j].size() and nums[j].front() - currIndex <= k){
                t+=('0'+j);
                newIndex = nums[j].front();
                break;
            }
        }
        k-=newIndex-currIndex;
        for(int j=0;j<10;j++){
            while(nums[j].size() and nums[j].front() <= newIndex){
                nums[j].pop_front();
            }
        }  
    }
    // for ascending order string
    cout << t.substr(0, t.length() - k) << "\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}