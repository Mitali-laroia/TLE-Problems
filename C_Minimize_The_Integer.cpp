#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(string s){
    int n = s.length();
    if(n==1) return s;
    string even,odd;
    for(int i=0;i<n;i++){
        if((s[i]-'0')%2==0) even+=s[i];
        else odd+=s[i];
    }
    int p1=0,p2=0;
    string ans;
    while(p1<even.size() and p2<odd.size()){
        if(even[p1]-'0'<odd[p2]-'0'){
            ans+=even[p1];
            p1++;
        } 
        else{
            ans+=odd[p2];
            p2++;
        }  
    }
    while(p1<even.size()){
        ans+=even[p1];
        p1++;
    }
    while(p2<odd.size()){
        ans+=odd[p2];
        p2++;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<"\n";
    }
    return 0;
}