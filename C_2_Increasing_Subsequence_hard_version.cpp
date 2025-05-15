#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    string ans = "";
    int left = 0, right = n-1, past = 0;

    while(left<=right){
        if(a[left]<a[right]){
            if(a[left]>past) {
                past = a[left];
                ans+="L";
                left++;
            }
            else if(a[right]>past){
                past = a[right];
                ans+="R";
                right--;
            }
            else break;
        }
        else if(a[right]<a[left]){
            if(a[right]>past) {
                past = a[right];
                ans+="R";
                right--;
            }
            else if(a[left]>past){
                past = a[left];
                ans+="L";
                left++;
            }
            else break;
        }
        else if(a[left]==a[right]){
            if(a[left]<=past) break;
            int newLeft = left+1, newRight = right-1;
            while(newLeft<=right && a[newLeft] > a[newLeft-1]) newLeft++;
            while(newRight>=left && a[newRight] > a[newRight+1]) newRight--;
            if((newLeft-left)>=(right-newRight)) ans+= string((newLeft-left),'L');
            else ans+=string((right-newRight),'R');
            break;
        }
    }
    cout<<ans.size()<<"\n"<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}