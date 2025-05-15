#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = 0;

    for(int i=0;i<(k+1)/2;i++){
        vector<int> f(26);
        for(int j=0;j<n;j+=k){
            f[s[j+i]-'a']++;
            if(j+i != j+k-1-i) f[s[j+k-1-i]-'a']++;
        }
        ans+= (accumulate(f.begin(), f.end(), 0) - *max_element(f.begin(), f.end()));
    }
    cout<<ans<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}