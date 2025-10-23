#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    map<char,int> mp;
    mp['h'] = 1;
    mp['e'] = 1;
    mp['l'] = 2;
    mp['o'] = 1;

    string temp = "";
    for(int i=0;i<n;i++){
        char ch = s[i];
        if(ch=='h' and mp['h']){
            temp+=ch;
            mp['h']--;
        }
        if(ch=='e' and mp['e'] and temp[temp.length()-1]=='h'){
            temp+=ch;
            mp['e']--;
        }
        if(ch=='l' and mp['l']){
            if(temp[temp.length()-1]=='e'){
                temp+=ch;
                mp['l']--;
            }
            else if(temp[temp.length()-1]=='l' and mp['l']){
                temp+=ch;
                mp['l']--;
            }
        }
        if(ch=='o' and mp['o'] and temp[temp.length()-1]=='l' and mp['l']==0){
            temp+=ch;
            mp['o']--;
        }
        if(temp=="hello"){
            cout<<"YES\n";
            return;
        }
    }

    // cout<<temp<<":";
    if(temp=="hello") cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    solve();
    return 0;
}