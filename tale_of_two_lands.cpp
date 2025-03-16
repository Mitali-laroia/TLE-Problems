#inclue<bits/stdc++h>
using namespace std;

int check(vector<int>v, int num,int index, int n){
    int low = index+1;
    int high = n;
    int high_index = index;

    while(low<=high){
        int mid = low+(high-low)/2;
        if(v[mid]<=2*num){
            high_index = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return high_index-index;
}
int solve(vector<int> v, int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        int num = v[i];
        int pairs = check(v,num,i,n);
        ans+=pairs;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    cout<<solve(v,n);
    return 0;
}