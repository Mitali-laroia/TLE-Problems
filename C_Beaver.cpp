#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(string s,vector<string> v,int n){
    int m = s.length();
    map<string,int> mp;
    for(int i=0;i<n;i++) mp[v[i]]++;
    int len = 0,pos=0;

    for(int left=0,right=0;right<m;right++){
        bool containBoring = false;
        int temp = 0;
        for(int j=max(left,right-10);j<=right;j++){
            if(mp.find(s.substr(j,right-j+1))!=mp.end()){
                containBoring = true;
                temp = j;
                break; 
            }
        }

        if(containBoring){
            left = temp+1;
            right--;
        }
        else{
            if(right-left+1 > len){
                len = right-left+1;
                pos = left;
            }
        }
    }
    cout<<len<<" "<<pos<<"\n";
}

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    solve(s,v,n);
    return 0;
}