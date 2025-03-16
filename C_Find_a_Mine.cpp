#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int dist;
        cout<<"? 1 1"<<endl;
        cin>>dist;
        int x1,y1,x2,y2;
        // x+y=d+2
        x1 = min(dist+1,n);
        y1 = dist+2-x1;
        y2 = min(dist+1,m);
        x2 = dist+2-y2;
        int dist1,dist2;
        cout<<"? "<<x1<<" "<<y1<<endl;
        cin>>dist1;
        int p1 = x1-dist1/2, p2=y1+dist1/2;
        cout<<"? "<<x2<<" "<<y2<<endl;
        cin>>dist2;
        int p3 = x2+dist2/2, p4=y2-dist2/2;
        int dist3;
        cout<<"? "<<p1<<" "<<p2<<endl;
        cin>>dist3;
        if(dist3==0) cout<<"! "<<p1<<" "<<p2<<endl;
        else cout<<"! "<<p3<<" "<<p4<<endl;
    }
    return 0;
}