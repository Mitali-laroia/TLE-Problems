#include<bits/stdc++.h>
#define int long long int
using namespace std;

int binomial_exp(int a,int b){
    int res = 1;
    while(b>0){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int ans = 0;
    vector<vector<int>> v(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    vector<vector<int>> row_count(n,vector<int>(2));
    vector<vector<int>> col_count(m,vector<int>(2));

    for(int i=0;i<m;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            // cout<<i<<":"<<j<<"->";
            if(v[j][i]==1) count++;
        }
        col_count[i][1] = count;
        col_count[i][0] = n-count;
        // cout<<i<<" "<<col_count[i][0]<<" "<<col_count[i][1]<<"\n";
        ans+=binomial_exp(2,col_count[i][0])-1;
        ans+=binomial_exp(2,col_count[i][1])-1;
    }

    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<m;j++){
            if(v[i][j]==1) count++;
        }
        row_count[i][1] = count;
        row_count[i][0] = m-count;
        // cout<<i<<" "<<row_count[i][0]<<" "<<row_count[i][1]<<"\n";
        ans+=binomial_exp(2,row_count[i][0])-(row_count[i][0]+1);
        ans+=binomial_exp(2,row_count[i][1])-(row_count[i][1]+1);
    }

    cout<<ans<<"\n";
}

signed main(){
    solve();
    return 0;
}