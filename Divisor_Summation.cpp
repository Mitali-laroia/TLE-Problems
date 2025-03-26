#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<int,int>> primeFactorization(int x,vector<int>& spf){
    vector<pair<int,int>> ans;
    // int count = 0;
    // ans.push_back({1,1});
    while(x!=1){
        int prime = spf[x];
        // cout<<prime<<" "<<x<<" ";
        int count = 0;
        while(x%prime==0){
            x = x/prime;
            count++;
        }
        ans.push_back({prime,count});
    }
    
    return ans;
}

int solve(int n,vector<int> spf){
    // cout<<"after"<<spf[n]<<":";
    vector<pair<int,int>> factors = primeFactorization(n,spf);
    int ans = 1;
    for(int i=0;i<factors.size();i++){
        int p = factors[i].first;
        int e = factors[i].second;
        // cout<<p<<":"<<e<<" ";
        float temp = (float)(pow(p,e+1)-1)/(p-1);
        ans = ans*temp;
    }
    return ans-n;
}

int divSum(int num){
    int result = 0;
    if(num == 1) 
      return result;
    for (int i=2; i<=sqrt(num); i++){
        if (num%i==0){
            if (i==(num/i))
                result += i;
            else
                result += (i + num/i);
        }
    }
    return (result + 1);
}

int main(){
    int t;
    cin>>t;
    int maxN = 500001;
    vector<bool> isPrime(maxN,1);
    vector<int> spf(1e6,1e9);
    // cout<<"before"<<spf[n]<<":";
    for(ll i=2;i<maxN;i++){
        if(isPrime[i]){
            spf[i] = i;
            for(ll j=i*i;j<maxN;j+=i){
                isPrime[j] = false;
                spf[j] = min(spf[j],(int)i);
            }
        }
    }
    while(t--){
        int n;
        cin>>n;
        cout<<divSum(n)<<"\n";
    }
    return 0;
}