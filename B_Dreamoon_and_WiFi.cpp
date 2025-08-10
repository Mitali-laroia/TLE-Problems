#include<bits/stdc++.h>
using namespace std;

void possible_positions(vector<int> &res, int pos, int index, string s2){
    if(index==s2.length()){
        res.push_back(pos);
        return;
    }
    if(s2[index]=='+') possible_positions(res,pos+1,index+1,s2);
    if(s2[index]=='-') possible_positions(res,pos-1,index+1,s2);
    if(s2[index]=='?'){
        possible_positions(res,pos-1,index+1,s2);
        possible_positions(res,pos+1,index+1,s2);
    }
}

void solve(){
    string s1, s2;
    cin>>s1;
    cin>>s2;
    int n = s1.length();
    int original_pos = 0;
    for(int i=0;i<n;i++){
        if(s1[i]=='+') original_pos++;
        else original_pos--;
    }
    vector<int> res;
    possible_positions(res, 0, 0, s2);
    // cout<<res[0]<<" ";
    double prob = 0.0;
    double correct_pos = 0.0;
    for(int i=0;i<res.size();i++){
        if(res[i]==original_pos) correct_pos++;
    }
    prob = (double) correct_pos/(double) res.size();
    cout<<fixed<<setprecision(12)<<prob<<"\n";
}

int main(){
    solve();
    return 0;
}