#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int maxN = 1e7+1;
vector<int> isPrime(maxN+1,false);
vector<int> spf(maxN+1);

ll binpow(int a,int b){
    ll res = 1;
	while (b){
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

void seive(){
    for (int i = 2; i < maxN; i++) spf[i] = i;
	for (int i = 2; i < maxN; i++)
	{
		if (spf[i] == i)
		{	for (ll j = i * 1ll * i; j < maxN; j += i)
			{
				if (j == spf[j]) spf[j] = i;
			}
		}
	}
}

void solve(){
    seive();
    ll n,m;
    cin>>n>>m;
    vector<ll> num(n),denom(m);
    for(ll i=0;i<n;i++) cin>>num[i];
    for(ll i=0;i<m;i++) cin>>denom[i];
    map<int,int> prime_num,prime_denom,minpower;

    for(int i=0;i<n;i++){
        int x = num[i];
        while(x>1){
            int p = spf[x];
            int count = 0;
            while(x%p==0){
                x = x/p;
                count++;
            }
            prime_num[p]+= count;
        }
    }

    for(int i=0;i<m;i++){
        int x = denom[i];
        while(x>1){
            int p = spf[x];
            int count = 0;
            while(x%p==0){
                x = x/p;
                count++;
            }
            prime_denom[p]+= count;
        }
    }

    for(auto it:prime_num){
        minpower[it.first] = min(prime_denom[it.first],it.second);
    }
    prime_denom = prime_num = minpower;

    for(int i=0;i<n;i++){
        int x = num[i];
        while(x>1){
            int count = 0;
            int p = spf[x];
            while(x%p==0){
                count++;
                x=x/p;
            }
            count = min(count,prime_num[p]);
            prime_num[p]-=count;
            num[i]/=binpow(p,count);
        }
    }

    for(int i=0;i<m;i++){
        int x = denom[i];
        while(x>1){
            int count = 0;
            int p = spf[x];
            while(x%p==0){
                count++;
                x=x/p;
            }
            count = min(count,prime_denom[p]);
            prime_denom[p]-=count;
            denom[i]/=binpow(p,count);
        }
    }

    cout<<num.size()<<" "<<denom.size()<<"\n";
    for(int i=0;i<n;i++) cout<<num[i]<<" ";
    cout<<"\n";
    for(int i=0;i<m;i++) cout<<denom[i]<<" ";
}

int main(){
    solve();
    return 0;
}