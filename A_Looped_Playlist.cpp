#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(vector<ll> a,ll n,ll p){
    ll ans = LONG_LONG_MAX;
    ll index = -1;
    ll sum = 0,num = 0;
    for(ll i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum<p){
        num = p/sum;
        p = p%sum;
    }
    // fixing the left instead of right poller
    for(ll left=0;left<n;left++){
        ll right = left;
        ll sum_temp = 0,count=0;
        while(sum_temp<p){
            sum_temp+=a[right];
            count++;
            right = (right+1)%n;
        }
        if(count<ans){
            ans = count;
            index = left+1;
        }
    }
    
    cout<<index<<" "<<ans+(num)*n<<"\n";
    return;
}

int main(){
    ll n,p;
    cin>>n>>p;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    solve(a,n,p);
    return 0;
}