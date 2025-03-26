#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;

		set<ll>current_divisors;
		vector<ll> newdivisors;
		ll ans = 0;
        vector<int> a(n);

		for(ll i = 0; i<n; i++){
			cin>>a[i];
			ll flag = 0;

			for(auto j:current_divisors){
				if(j%a[i]==0)newdivisors.push_back(j/a[i]);
			}

			for(auto j:newdivisors){ 
				if(j == 1)flag = 1;
				current_divisors.insert(j); // n*logx*log(logx)
			}

			newdivisors.clear();
            
			if(flag){
				ans++;
				current_divisors.clear();
			}
			if(x%a[i]==0)
			current_divisors.insert(x/a[i]);
		}
		cout<<ans+1<<endl;
	}
	return 0;
}

// TC = O(n*logx*log(logx))
// SC = O(n)