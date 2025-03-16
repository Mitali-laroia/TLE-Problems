#include<bits/stdc++.h>
using namespace std;

void solve(int m,int n){
    int low = 1, high = m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        cout<<1<<endl;
        cin>>x;
        if(x==0) return;
        a[i] = x;
    }
    int ans = -1;
    int count = 0;

    while(low<=high){
        int mid = (low+high)/2;
        cout<<mid<<endl;
        int q;
        cin>>q;
        if(q==0) return ;
        else if(q*a[count]==-1){
            high = mid-1;
        }
        else low = mid+1;
        count = (count+1)%n;
    }
    return;
}

int main(){
    int m,n;
    cin>>m>>n;
    solve(m,n);
    return 0;
}