#include<bits/stdc++.h>
using namespace std;

void tell(int index){
    cout<<"! "<<index<<endl;
}

int ask(int left, int right){
    int sum;
    cout<<"? "<<left<<" "<<right<<endl;
    cin>>sum;
    return sum;
}

int solve(int n, int k){
    // int num_zeros = n-ask(1,n);
    int count_k = k;
    int low=1, high=n;
    int ans;

    while(low<=high){
        int mid = (low+high)/2;
        int sum_pre = ask(1,mid);
        // int sum_post = ask(mid+1,high);
        int num_zeros_pre = mid-sum_pre;
        // int num_zeros_post = mid-high-sum_post;
        if(num_zeros_pre==k) ans = mid;
        if(num_zeros_pre>=k){
            high = mid-1;
        }
        else{
            // count_k-=num_zeros_pre;
            low = mid+1;
        } 
    }

    return ans;
}

int main(){
    int n,t;
    cin>>n>>t;
    int k;
    cin>>k;
    int ans = solve(n,k);
    tell(ans);
    return 0;
}