#include<bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> sheeps;
    int empty = 0;

    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        if(ch=='.') empty++;
        else if(ch=='*') sheeps.push_back(empty);
    }

    int mid = (sheeps.size()-1)/2;
    int ans = 0;
    for(int i=0;i<sheeps.size();i++){
        ans+=abs(sheeps[mid]-sheeps[i]);
    }
    cout<<ans<<"\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}