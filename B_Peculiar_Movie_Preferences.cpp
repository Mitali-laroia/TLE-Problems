#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<string,vector<int>> mpe, mpo;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(s[i].size()%2==0) mpe[s[i]].push_back(i);
        else mpo[s[i]].push_back(i);
    }

    for(int i=0;i<n;i++){
        string t = s[i];
        if(t.size()%2==0){
            reverse(t.begin(), t.end());
            if(mpe.count(t)){
                cout<<"YES\n";
                return;
            }

            char last = t[t.size()-1];
            t.pop_back();
            reverse(t.begin(), t.end());
            if(mpo.count(t) && mpo[t][0]<i){
                cout<<"YES\n";
                return;
            }
            t+=last;
            reverse(t.begin(), t.end());

            last = t[t.size()-1];
            t.pop_back();
            reverse(t.begin(), t.end());
            if(mpo.count(t) && mpo[t][mpo[t].size()-1]>i){
                cout<<"YES\n";
                return;
            }
            reverse(t.begin(), t.end());
            t+=last;
        }
        else {
            reverse(t.begin(), t.end());
            if(mpo.count(t)){
                cout<<"YES\n";
                return;
            }

            char last = t[t.size()-1];
            t.pop_back();
            if(mpe.count(t) && mpe[t][0]<i){
                cout<<"YES\n";
                return;
            }
            t+=last;
            reverse(t.begin(), t.end());

            last = t[t.size()-1];
            t.pop_back();
            reverse(t.begin(), t.end());
            if(mpe.count(t) && mpe[t][mpe[t].size()-1]>i){
                cout<<"YES\n";
                return;
            }
            reverse(t.begin(), t.end());
            t+=last;
        }
    }
    cout<<"NO\n";
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}