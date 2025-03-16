#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,stairs,elevator,velocity;
    cin>>n>>m>>stairs>>elevator>>velocity;
    vector<int> stair_col(stairs);
    vector<int> elevator_col(elevator);
    for(int i=0;i<stairs;i++){
        cin>>stair_col[i];
    }
    for(int i=0;i<elevator;i++){
        cin>>elevator_col[i];
    }
    int q;
    cin>>q;
    while(q--){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2){
                cout<<abs(y1-y2)<<endl;
            }
            else{
                int ans = INT_MAX;
            if(stairs>0){
                int first_distance = abs(x1-x2);
                int index = lower_bound(stair_col.begin(),stair_col.end(),y1)-stair_col.begin();
                if(index<stairs){
                    int second_distance = abs(y1-stair_col[index])+abs(y2-stair_col[index]);
                    ans = min(ans,first_distance+second_distance);
                }
                if(index-1>=0){
                    int second_distance = abs(y1-stair_col[index-1])+abs(y2-stair_col[index-1]);
                    ans = min(ans,first_distance+second_distance);
                }
                int index2= lower_bound(stair_col.begin(),stair_col.end(),y2)-stair_col.begin();
                if(index2<stairs){
                    int second_distance = abs(y1-stair_col[index2])+abs(y2-stair_col[index2]);
                    ans = min(ans,first_distance+second_distance);
                }
                if(index2-1>=0){
                    int second_distance = abs(y1-stair_col[index2-1])+abs(y2-stair_col[index2-1]);
                    ans = min(ans,first_distance+second_distance);
                }
            }
            if(elevator>0){
                int first_distance = (abs(x2-x1)+velocity-1)/velocity;
                int index = lower_bound(elevator_col.begin(),elevator_col.end(),y1)-elevator_col.begin();
                if(index<elevator){
                    int second_distance = abs(y1-elevator_col[index])+abs(y2-elevator_col[index]);
                    ans = min(ans,first_distance+second_distance);
                }
                if(index-1>=0){
                    int second_distance = abs(y1-elevator_col[index-1])+abs(y2-elevator_col[index-1]);
                    ans = min(ans,first_distance+second_distance);
                }
                int index2= lower_bound(elevator_col.begin(),elevator_col.end(),y2)-elevator_col.begin();
                if(index2<elevator){
                    int second_distance = abs(y1-elevator_col[index2])+abs(y2-elevator_col[index2]);
                    ans = min(ans,first_distance+second_distance);
                }
                if(index2-1>=0){
                    int second_distance = abs(y1-elevator_col[index2-1])+abs(y2-elevator_col[index2-1]);
                    ans = min(ans,first_distance+second_distance);
                }
            }
            cout<<ans<<endl;
            }
        }
    return 0;
}