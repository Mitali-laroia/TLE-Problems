#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"infinity\n";
        return;
    }
    if(b>a or a==0){
        cout<<0<<"\n";
        return;
    }
    int ans = 0;
    for(int i=1;i*i<=(a-b);i++){
        if((a-b)%i==0){
            if(i>b) ans++;
            if((a-b)/i>b and (a-b)/i!=i) ans++;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}