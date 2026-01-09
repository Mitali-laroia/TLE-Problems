#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int q;
    cin>>q;
    char sm1 = 'a', lg1 = 'a', sm2 = 'a', lg2 = 'a';
    int len1 = 1, len2 = 1;

    while(q--) {
        int op, k;
        string s;
        cin>>op>>k>>s;
        if(sm1<lg2) cout<<"YES\n";
        else {
            if(op==1) {
                int n = s.size();
                for(int i=0;i<n;i++){
                    sm1 = min(s[i], sm1);
                    lg1 = max(s[i], lg1);
                }
                len1+=n*k;
            }
            else {
                int n = s.size();
                for(int i=0;i<n;i++){
                    sm2 = min(s[i], sm2);
                    lg2 = max(s[i], lg2);
                }
                len2+=n*k;
            }
            if(sm1<lg2) cout<<"YES\n";
            else if(len1<len2){
                if(lg1>lg2) cout<<"NO\n";
                else cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}