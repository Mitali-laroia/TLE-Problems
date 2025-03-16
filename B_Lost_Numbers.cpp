#include<bits/stdc++.h>
using namespace std;

int ask(int i,int j){
    int mul;
    cout<<"? "<<i<<" "<<j<<endl;
    cin>>mul;
    return mul;
}

void tell(vector<int> v){
    cout<<"! ";
    for(int num: v){
        cout<<num<<" ";
    }
    cout<<endl;
}

void solve(){
    vector<int> res = {4, 8, 15, 16, 23, 42};
    unordered_map<int,pair<int,int>> mp;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            mp[res[i]*res[j]] = {res[i],res[j]};
        }
    }
    
    vector<int> v(6);
    int first_mul = ask(1,2);
    int second_mul = ask(2,3);
    pair<int,int> first_pair = mp[first_mul];
    pair<int,int> second_pair = mp[second_mul];
    if(first_pair.first==second_pair.first){
        v[1] = first_pair.first;
        v[0] = first_pair.second;
        v[2] = second_pair.second;
    } 
    else if(first_pair.first==second_pair.second){
        v[1] = first_pair.first;
        v[0] = first_pair.second;
        v[2] = second_pair.first;
    } 
    else if(first_pair.second==second_pair.first){
        v[1] = first_pair.second;
        v[0] = first_pair.first;
        v[2] = second_pair.second;
    } 
    else if(first_pair.second==second_pair.second){
        v[1] = first_pair.second;
        v[0] = first_pair.first;
        v[2] = second_pair.first;
    } 

    int third_mul = ask(4,5);
    int forth_mul = ask(5,6);
    pair<int,int> third_pair = mp[third_mul];
    pair<int,int> forth_pair = mp[forth_mul];
    if(third_pair.first==forth_pair.first){
        v[4] = third_pair.first;
        v[3] = third_pair.second;
        v[5] = forth_pair.second;
    } 
    else if(third_pair.first==forth_pair.second){
        v[4] = third_pair.first;
        v[3] = third_pair.second;
        v[5] = forth_pair.first;
    } 
    else if(third_pair.second==forth_pair.first){
        v[4] = third_pair.second;
        v[3] = third_pair.first;
        v[5] = forth_pair.second;
    } 
    else if(third_pair.second==forth_pair.second){
        v[4] = third_pair.second;
        v[3] = third_pair.first;
        v[5] = forth_pair.first;
    } 

    tell(v);
}

int main(){
    solve();
    return 0;
}