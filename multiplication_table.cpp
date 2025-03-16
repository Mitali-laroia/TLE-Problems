#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(ll median, ll n){
    ll count = 0;
    ll limit = (n*n+1)/2;
    for(int i=0;i<n;i++){
        count+= min(n,median/(i+1));
        if(count>=limit) return true;
    }
    return count>=limit;
}

void solve(ll n){
    ll low = 1;
    ll high = n*n;
    ll ans = -1;

    while(low<=high){
      ll mid = low + (high-low)/2;
      if(check(mid,n)){
        ans = mid;
        high = mid-1;
      }  
      else low = mid+1;
    }

    cout<<ans;
}

int main(){
    ll n;
    cin>>n;
    solve(n);
    return 0;
}