#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> loadGrid(const string &filename) {
    vector<vector<char>> grid;
    ifstream file(filename);
    string line;

    while(getline(file, line)) {
        if(!line.empty() and line.back() == '\r') line.pop_back();
        if(line.empty()) continue;
        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }
    return grid;
}

void solve(vector<vector<char>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == '@'){
                int adj = 0;
                if(i-1>=0 and j-1>=0 and matrix[i-1][j-1]=='@') adj++;
                if(i-1>=0 and matrix[i-1][j]=='@') adj++;
                if(i-1>=0 and j+1<m and matrix[i-1][j+1]=='@') adj++;
                if(j+1<m and matrix[i][j+1]=='@')  adj++;
                if(i+1<n and j+1<m and matrix[i+1][j+1]=='@') adj++;
                if(i+1<n and matrix[i+1][j]=='@') adj++;
                if(i+1<n and j-1>=0 and matrix[i+1][j-1]=='@') adj++;
                if(j-1>=0 and matrix[i][j-1]=='@') adj++;

                if(adj < 4) ans++;
            }
        }
    }
    cout<<ans<<"\n";
}

int main() {
    vector<vector<char>> grid = loadGrid("/mnt/c/Users/04042/Documents/tle/combanitorics/input.txt");
    solve(grid);
    return 0;
}