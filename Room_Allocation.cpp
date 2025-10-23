#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second.first;
        v[i].second.second = i;
    }
    sort(v.begin(), v.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> rooms;
    // pq: time,index
    vector<int> room_allocated_customer(n);
    for(int i=0;i<n;i++){
        if(rooms.empty()){
            rooms.push({v[i].second.first, 1});
            room_allocated_customer[v[i].second.second]=1;
        }
        else{
            pair<int,int> t = rooms.top();
            if(v[i].first <= t.first){
                int size = rooms.size();
                room_allocated_customer[v[i].second.second] = size+1;
                rooms.push({v[i].second.first, size+1});
            }
            else {
                room_allocated_customer[v[i].second.second] = t.second;
                t.first = v[i].second.first;
                rooms.pop();
                rooms.push(t);
            }
        } 
    }
    cout<<rooms.size()<<"\n";
    for(int i=0;i<n;i++) cout<<room_allocated_customer[i]<<" ";
}

signed main() {
    solve();
    return 0;
}