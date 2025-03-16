#include<bits/stdc++.h>
using namespace std;

int ask(int left, int right){
    int num;
    cout<<"? "<<left<<" "<<right<<endl;
    cin>>num;
    return num;
}

void tell(vector<int> v, int n){
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int sum = ask(1,n);
    vector<int> v(n+1);
    int prev = sum;
    for(int i=n-1;i>=2;i--){
        int temp = ask(1,i);
        // cout<<"temp: "<<temp<<endl;
        v[i+1] = prev-temp;
        prev = temp;
    }
    int sum_of_2_3 = ask(2,3);
    v[2] = sum_of_2_3 - v[3];
    v[1] = prev-v[2];
    tell(v,n);
    return 0;
}