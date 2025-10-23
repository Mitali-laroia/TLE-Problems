#include<bits/stdc++.h>
#define int long long
using namespace std;

void get_max_num(int comp_usb, int comp_ps2, int comp_both, vector<int> cost_usb, vector<int> cost_ps2){
    int num = 0, cost = 0;
    int index_usb = 0, index_ps2 = 0;
    while(comp_usb and index_usb<cost_usb.size()){
        num++;
        cost+=cost_usb[index_usb];
        index_usb++;
        comp_usb--;
    }
    while(comp_ps2 and index_ps2<cost_ps2.size()){
        num++;
        cost+=cost_ps2[index_ps2];
        index_ps2++;
        comp_ps2--;
    }

    vector<int> cost_both;
    for(int i=index_ps2;i<cost_ps2.size();i++){
        cost_both.push_back(cost_ps2[i]);
    }
    for(int i=index_usb;i<cost_usb.size();i++){
        cost_both.push_back(cost_usb[i]);
    }
    sort(cost_both.begin(), cost_both.end());

    int index_both = 0;
    while(comp_both and index_both<cost_both.size()){
        num++;
        cost+=cost_both[index_both];
        index_both++;
        comp_both--;
    }
    
    cout<<num<<" "<<cost<<"\n";
}

void solve(){
    int comp_usb, comp_ps2, comp_both;
    cin>>comp_usb>>comp_ps2>>comp_both;

    int mouses;
    cin>>mouses;
    vector<int> cost_usb, cost_ps2;

    for(int i=1;i<=mouses;i++){
        int num;
        string type;
        cin>>num>>type;
        if(type=="USB") cost_usb.push_back(num);
        else cost_ps2.push_back(num);
    }

    sort(cost_usb.begin(), cost_usb.end());
    sort(cost_ps2.begin(), cost_ps2.end());

    int num = 0, cost = 0;
    int index_usb = 0, index_ps2 = 0;
    while(comp_usb and index_usb<cost_usb.size()){
        num++;
        cost+=cost_usb[index_usb];
        index_usb++;
        comp_usb--;
    }
    while(comp_ps2 and index_ps2<cost_ps2.size()){
        num++;
        cost+=cost_ps2[index_ps2];
        index_ps2++;
        comp_ps2--;
    }

    vector<int> cost_both;
    for(int i=index_ps2;i<cost_ps2.size();i++){
        cost_both.push_back(cost_ps2[i]);
    }
    for(int i=index_usb;i<cost_usb.size();i++){
        cost_both.push_back(cost_usb[i]);
    }
    sort(cost_both.begin(), cost_both.end());

    int index_both = 0;
    while(comp_both and index_both<cost_both.size()){
        num++;
        cost+=cost_both[index_both];
        index_both++;
        comp_both--;
    }
    
    cout<<num<<" "<<cost<<"\n";
}

signed main(){
    solve();
    return 0;
}