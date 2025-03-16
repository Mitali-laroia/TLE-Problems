
#include<bits/stdc++.h>
#define int long long int
#define ff first
#define ss second
using namespace std;





signed main(){
    int n,m,c1,c2,s;cin>>n>>m>>c1>>c2>>s;
    vector<int> stair;
    vector<int> ele;
    int value;
    for(int i=0;i<c1;i++) {
        cin>>value;
        stair.push_back(value);
    }
    for(int i=0;i<c2;i++) {
        cin>>value;
        ele.push_back(value);
    }
    int q;cin>>q;
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2){
            cout<<abs(y1-y2)<<endl;
            continue;
        }
        int ans=2*n+2*m;
       if(c1>0){ 
        int a=abs(x1-x2);
        int u=lower_bound(stair.begin(),stair.end(),y1)-stair.begin();
        if(u<c1){
            int temp=abs(y1-stair[u])+abs(y2-stair[u]);
            ans=min(ans,temp+a);
        }
        if(u-1>=0){
            int temp=abs(y1-stair[u-1])+abs(y2-stair[u-1]);
            ans=min(ans,temp+a);
        }
        int v=lower_bound(stair.begin(),stair.end(),y2)-stair.begin();
        if(v<c1){
            int temp=abs(y1-stair[v])+abs(y2-stair[v]);
            ans=min(ans,temp+a);
        }
        if(v-1>=0){
            int temp=abs(y1-stair[v-1])+abs(y2-stair[v-1]);
            ans=min(ans,temp+a);
        }}

        if(c2>0){
            int a=((abs(x1-x2)+s-1)/s);
            int u=lower_bound(ele.begin(),ele.end(),y1)-ele.begin();
            if(u<c2){
                int temp=abs(y1-ele[u])+abs(y2-ele[u]);
                ans=min(ans,temp+a);// (abs(x1-x2)+s-1)/s;
            }
            if(u-1>=0){
                int temp=abs(y1-ele[u-1])+abs(y2-ele[u-1]);
                ans=min(ans,temp+a);
            }
            int v=lower_bound(ele.begin(),ele.end(),y2)-ele.begin();
            if(v<c2){
                int temp=abs(y1-ele[v])+abs(y2-ele[v]);
                ans=min(ans,temp+a);
            }
            if(v-1>=0){
                int temp=abs(y1-ele[v-1])+abs(y2-ele[v-1]);
                ans=min(ans,temp+a);
            }
        }
        cout<<ans<<endl;
        // ans+=abs(y1-y2);
    }

    return 0;
}