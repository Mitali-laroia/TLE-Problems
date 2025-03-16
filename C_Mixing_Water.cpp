\#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vb=vector<bool>;
using vvb=vector<vb>;
using vi=vector<int>;
using vvi=vector<vi>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vc=vector<char>;
using vvc=vector<vc>;
using vs=vector<string>;
using pll=pair<ll,ll>;
const ll mod=1e9+7, inf=1e10, N=2e5+5;
#define pb push_back
#define fo(i, n) for (long long i = 0; i < n; i++)
#define fr(i, n) for (ll i = n - 1; i >= 0;i--)
#define cin(a,n)   vll a(n); fo(i,n) {cin>>a[i];}
#define prv(a) for(auto i:a) cout<<i<<" ";
#define f first
#define s second
void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}

void solve(){
    long double hot,cold,tar;
    cin>>hot>>cold>>tar;
    if(tar>=hot){
        cout<<1<<endl;
        return;
    }
    if(tar<=(hot+cold)/2){
        cout<<2<<endl;return;
    }
    //t0>=t1>=t2.. pouring k+1 hot, k even cups
    ll l=0, r=1e9,ans=1;
    long double mndiff=abs(tar-hot);
    while(l<=r){
        ll mid=(l+r)/2;
        long double val=((mid+1)*hot+mid*cold)/(2*mid+1);
        if(abs(val-tar)<mndiff){
            ans=mid;
            mndiff=abs(val-tar);
        }
        else if(abs(val-tar)==mndiff&& mid<ans)
            ans=mid;
        if(val>tar){
            l=mid+1;
        }else r=mid-1;
    }
    cout<<2*ans+1<<endl;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}