#include<bits/stdc++.h>
using namespace std;

const int num_alphabets = 'z'-'a'+1;
int cnt[num_alphabets][5000][num_alphabets];

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    
    for(int i=0;i<n;i++){
        int cur = s[i]-'a';
        for(int j=1;j<n;j++){
            int next = s[(i+j)%n]-'a';
            cnt[cur][j][next]++;
        }
    }

    double count = 0;
    for(int i=0;i<num_alphabets;i++){
        double mx = 0;
        for(int j=1;j<n;j++){
            double c = 0;
            for(int k=0;k<num_alphabets;k++){
                if(cnt[i][j][k] == 1) c++;
            }
            mx = max(mx,c);
        }
        count+=mx;
    }

    cout<<fixed<<setprecision(10)<<(double) count/n<<"\n";
}

int main(){
    solve();
    return 0;
}