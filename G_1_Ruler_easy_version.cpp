#include<bits/stdc++.h>
using namespace std;

bool check(int num){
    cout<<"? "<<num<<" "<<num<<endl;
    int area;
    cin>>area;
    return area==(num*num);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int low = 2, high = 999;
        int ans = 999;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(mid)){
                // ans = mid;
                low = mid+1;
            }
            else {
                ans = mid;
                high = mid-1;
            }
        }
        cout<<"! "<<ans<<endl;
    }
    return 0;
}