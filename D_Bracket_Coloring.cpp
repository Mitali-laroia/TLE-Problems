#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2 || (count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')'))){
        cout<<"-1\n";
        return;
    }
    
    vector<int> ans(n);
    int cnt = 0;
    int pos, neg;
    pos = 1, neg = 2;
    if(s[0]==')') pos = 2, neg = 1;

    for(int i=0;i<n;i++){
        if(s[i]=='('){
            cnt++;
            if(cnt>0) ans[i] = pos;
            else ans[i] = neg;
        }
        else{
            cnt--;
            if(cnt<0) ans[i] = neg;
            else ans[i] = pos;
        }
    }

    if(*max_element(ans.begin(), ans.end()) == *min_element(ans.begin(), ans.end())){
        cout<<"1\n";
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    else{
        cout<<"2\n";
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}