#include<bits/stdc++.h>
using namespace std;

int solve(string s,string t){
    int n = s.length(), m = t.length();
    int ans = 0;
    int start = m-1;
    vector<int> locations(m);
    for(int i=n-1;i>=0;i--){
        if(s[i]==t[start]){
            locations[start] = i;
            start--;
        }
        if(start<0){
            ans = i;
            break;
        }
    }

    start = 0;
    int i = 0;
    while(start<m-1){
        while(s[i]!=t[start]) i++;
        i++;
        start++;
        ans = max(ans,n-(n-locations[start])-i);
    }
    while(s[i]!=t[start]) i++;
    ans = max(ans,n-i-1);
    return ans;
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<solve(s,t)<<endl;
    return 0;
}