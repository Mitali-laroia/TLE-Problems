#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> freq(m+1);
    vector<int> changes;
    int changeSum = 0;
    for(int i=0;i<n;i++){
        if(a[i]>m) changes.push_back(i);
        else {
            if(freq[a[i]] ==  n/m) changes.push_back(i);
            else freq[a[i]]++;
        }
    }

    for(int i=1;i<=m;i++){
        while(freq[i]<n/m){
            a[changes.back()] = i;
            changes.pop_back();
            changeSum++;
            freq[i]++;
        }
    }

    cout<<n/m<<" "<<changeSum<<"\n";
    for(auto &i: a) cout<<i<<" ";
}

int main(){
    solve();
    return 0;
}