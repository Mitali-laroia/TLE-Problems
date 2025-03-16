#include<bits/stdc++.h>
using namespace std;

void ask(){
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
    int count = 0;
    for(int i=0;i<primes.size();i++){
        string ans;
        cout<<primes[i]<<endl;
        cin>>ans;
        if(ans=="yes") count++;
        if(count>1){
            cout<<"composite"<<endl;
            return;
        }
    }
    cout<<"prime"<<endl;
}

int main(){
    ask();
    return 0;
}