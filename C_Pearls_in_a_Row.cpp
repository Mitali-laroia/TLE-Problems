#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    unordered_map<int, vector<int>> mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]].push_back(i);
    }

    int ans = -1;
    vector<pair<int,int>> res;

    int i = 0;
    while(i<n){
        auto it = upper_bound(mp[v[i]].begin(), mp[v[i]].end(), i);
        // cout<<"index found: "<<*it<<"\n";
        if(it==mp[v[i]].end()){
            if(!res.empty() and res[res.size()-1].second-1 < i) res[res.size()-1].second = i+1;
            i++;
        } 
        else if(!res.empty() and i==res[res.size()-1].second-1) i++;
        else {
            if(res.empty()) {
                res.push_back({i+1,*it+1});
                i++;
                if(ans==-1) ans = 0;
                ans++;
            } 
            else {
                if(*it < res[res.size()-1].second-1) {
                    pair<int,int> last = res[res.size()-1];
                    res.pop_back();
                    res.push_back({last.first, *it+1});
                    i++;
                }
                else {
                    if(i>res[res.size()-1].second-1) {
                        res.push_back({res[res.size()-1].second+1, *it+1});
                        if(ans==-1) ans = 0;
                        ans++;
                    }
                    i++; 
                } 
            } 
        }
    }
    if(!res.empty() and res[0].first > 1) res[0].first = 1;
    cout<<ans<<"\n";
    for(int i=0;i<res.size();i++){
        cout<<res[i].first<<" "<<res[i].second<<"\n";
    }
    cout<<"\n";
}

signed main(){
    solve();
    return 0;
}