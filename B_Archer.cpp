#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    double prob_a_hits, prob_a_miss, prob_b_hits, prob_b_miss;
    prob_a_hits = (double)a/(double)b;
    prob_a_miss = 1-prob_a_hits;
    prob_b_hits = (double)c/(double)d;
    prob_b_miss = 1-prob_b_hits;

    double res = (double)prob_a_hits/(double)(1-prob_a_miss*prob_b_miss);
    cout<<fixed<<setprecision(12)<<res<<"\n";
}

int main(){
    solve();
    return 0;
}