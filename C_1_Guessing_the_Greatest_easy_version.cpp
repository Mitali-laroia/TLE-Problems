#include<bits/stdc++.h>
using namespace std;

int ask(int l, int r){
    int num;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>num;
    return num;
}

void tell(int num){
    cout<<"! "<<num<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    int secondMax = ask(1,n);
    if(n==1){
        if(secondMax==1) tell(2);
        else tell(1);
        return 0;
    }
    
    int ind = -1;
    if(secondMax!=1){
        ind = ask(1,secondMax);
    }

    if(ind==secondMax){
        int low = 1, high = secondMax-1;
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            if(ask(mid,secondMax)==secondMax){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        tell(ans);
    }
    else{
        int low = secondMax+1,high=n;
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            if(ask(secondMax,mid)==secondMax){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        tell(ans);
    }
    return 0;
}