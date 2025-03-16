#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;cin>>a>>b;
    int s1=0,s2=0;
    for(auto x:b)s2+=x-'0';int ans=0;
    for(int i=0;i<a.size();++i){
        s1+=a[i]-'0';
        if(i>=b.size())s1-=a[i-b.size()]-'0';
        if(i>=b.size()-1&&((s1&1)==(s2&1)))++ans;
    }
    cout<<ans<<"\n";
}