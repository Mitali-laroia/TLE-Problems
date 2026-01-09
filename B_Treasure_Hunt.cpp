#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin>>n;
    string kuro, shiro, katie;
    cin>>kuro>>shiro>>katie;
    int len = kuro.length();
    if(n>=len) {
        cout<<"Draw\n";
        return;
    }

    unordered_map<char,int> mp1, mp2, mp3;
    for(int i=0;i<len;i++){
        mp1[kuro[i]]++;
        mp2[shiro[i]]++;
        mp3[katie[i]]++;
    }
    int max1 = 0, max2 = 0, max3 = 0;
    for(auto it:mp1){
        max1 = max(max1, it.second);
    }
    for(auto it:mp2){
        max2 = max(max2, it.second);
    }
    for(auto it:mp3){
        max3 = max(max3, it.second);
    }

    if(n==1 and max1==len) max1 = len-1;
    else max1 = min(len, max1+n);

    if(n==1 and max2==len) max2 = len-1;
    else max2 = min(len, max2+n);

    if(n==1 and max3==len) max3 = len-1;
    else max3 = min(len, max3+n);

    if(max1>max2 and max1>max3) {
        cout<<"Kuro\n";
        return;
    } else if(max2>max3 and max2>max1) {
        cout<<"Shiro\n";
        return;
    } else if(max3>max2 and max3>max1) {
        cout<<"Katie\n";
        return;
    } else {
        cout<<"Draw\n";
        return;
    }
}

signed main() {
    solve();
    return 0;
}