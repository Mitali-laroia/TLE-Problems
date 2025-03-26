#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> freq(1e6+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    } 
    // int ans = 1;
    for(int i=1e6;i>=1;i--){
        int count = 0;
        for(int j=i;j<1e6+1;j+=i){
            count+=freq[j];
        }
        if(count>1){
            cout<<i<<"\n"; break;
        } 
    }
}

int main(){
    solve();
    return 0;
}