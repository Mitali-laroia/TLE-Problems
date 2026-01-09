#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int pay = 0;
    for(int i=0;i<n;){
        // trivial case when a[i] = 0 then we have to pay to make red
        if (a[i] == 0) {
            pay++;
            i++;
            continue;
        }

        //when a[i]>0, finding out the subarray of all postives
        int index = i;
        bool has2 = false;
        //checking in that subarray if there is a[i] = 2
        while(i<n and a[i]!=0) {
            if (a[i] == 2) {
                has2 = true;
            }
            i++;
        }
        //assuming that for this index we have to make it red
        pay++;
        // the i pointer has moved to the index till which we have postive numbers
        if(index-1>=0 and a[index-1] == 0) {
            // if the prev index = 0, then we have already converted it to red, 
            // see the very first condition in the loop, hence there is not need to pay a coin here, we use operation 2
            pay--;
            //if there is no two, then all 1s will get converted to red and we move on to next index
            if (!has2) {
                continue;
            }
        }
        //if the last index was two, then making it one, cause we used one coin
        if(i<n) {
            a[i] = 1;
            i++;
        }
    }
    cout<<pay<<"\n";
}

signed main() {
    solve();
    return 0;
}