#include<iostream>
#include<vector>
using namespace std;


int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

// 👉 safe function is checking we are bounce or not 
bool isSafe(int x, int y, vector<vector<bool>> & visited, int n, int m, vector<vector<int>> &grid){
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && visited[x][y] == 0);
}

void dfs(int i, int j, vector<vector<bool>> &visited, int n, int m, vector<vector<int>> &grid){
    // 👉 making visited cell as visited
    visited[i][j] = 1;
    // 👉 traversing to all 4 neighbours
    for(int k = 0; k<4; k++){
        int x = i + dx[k]; // 👉 dx is represent change in x
        int y = j + dy[k]; // 👉 dx is represent change in y
        if(isSafe(x,y,visited,n,m,grid)){
            dfs(x,y,visited,n,m,grid);
        }
    }
}


int numberOfEnclaves(vector<vector<int>> &grid) {
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,0));

    for(int i=0; i<n;i++){
        // 👉 for every row check it is 1 or not 
        if(grid[i][0]==1){ 
            dfs(i,0,visited,n,m,grid);
        }
        // 👉 for every row check the last column is 1 or not 
        if(grid[i][m-1]==1){
            dfs(i,m-1,visited,n,m,grid);
        }
    }

        // 👉 for every column check it is 1 or not 
    for(int j=0;j<m;j++){
        if(grid[0][j]==1){
            dfs(0,j,visited,n,m,grid);
        }
        // 👉 for every column check the last column is 1 or not 
        if(grid[n-1][j]==1){
            dfs(n-1,j,visited,n,m,grid);
        }
    }

// 👉 lastly check 
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            if(grid[i][j]== 1 && visited[i][j] == 0){
                ans++;
            }
        }
    }
    return ans;
}
// 👉 ⏲️ we are making this dfs for every row and every column boundary dfs in row ---> O(2n) + dfs in column O(2M)


int main()
{
    vector<vector<int>>grid {{0, 0, 0, 0},
                            {1, 0, 1, 0},
                            {0, 1, 1, 0},
                            {0, 0, 0, 0}};

    int ans = numberOfEnclaves(grid);
    cout << "ans is " << ans << endl;
    return 0;
}
