#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    int n = s.length();
    vector<char> answer(n);
    int left = 0, right = n-1;

    for(int i=0;i<n;i+=2){
        if(i==n-1){
            answer[left] = s[i];
        } 
        else if(s[i]==s[i+1]){
            answer[left] = s[i];
            answer[right] = s[i+1];
            left++;
            right--;
        } 
        else{
            if(s[i+1]==s[n-1]){
                int len = n-i-1;
                int firstHalf = ceil(len/2.0);
                int secondHalf = len-firstHalf;
                while(firstHalf--){
                    answer[left] = s[i+1];
                    left++;
                }
                answer[left] = s[i];
                while(secondHalf--){
                    answer[right] = s[i+1];
                    right--;
                }
                break;
            }
            else {
                for(int j=i+1;j<n;j++){
                    answer[left] = s[j];
                    left++;
                }
                answer[right] = s[i];
                break;
            }
        }
    }

    string res = "";
    for(int i=0;i<n;i++){
        res+=answer[i];
    }
    cout<<res<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}