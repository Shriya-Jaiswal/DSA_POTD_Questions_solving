#include<iostream>
#include<vector>
#include<limits.h>
#include<map>
#include<set>
using namespace std;

void putid(int id, int i,int j,vector<vector<int>>& grid,int m, int n, int &count ){
    if(i<0 || j<0 || i>=m || j>=n ){
        return;
    }
    else if(grid[i][j] >1 || grid[i][j]==0){
        return;
    }
    else{
        grid[i][j]=id;
        putid(id,i+1,j,grid,m,n,count);
        putid(id,i-1,j,grid,m,n,count);
        putid(id,i,j+1,grid,m,n,count);
        putid(id,i,j-1,grid,m,n,count);
        count++;
    }
}

bool checkvalid(int i, int j, int m, int n){
    if(i<0 || j<0 || i>=m || j>=n){
        return false;
    }
    return true;
}

int largestIsland(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    map<int,int> mp;
    int id = 2;
    int Max = INT_MIN;

    // 👉 calculate size of each island
    for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1){
                int count = 0;
                // 👉apply dfs
                putid(id,i,j,grid,m,n,count);
                mp.insert({id,count});
                id++;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                int sum = 0;
                set<int>s; // 👉 set will store unique value only
                if(checkvalid(i-1,j,m,n) && grid[i-1][j] >1 && s.find(grid[i-1][j]) == s.end()){
                    s.insert(grid[i-1][j]);
                    auto it = mp.find(grid[i-1][j]);
                    sum+=it->second;
                }
                if(checkvalid(i+1,j,m,n) && grid[i+1][j] >1 && s.find(grid[i+1][j]) == s.end()){
                    s.insert(grid[i+1][j]);
                    auto it = mp.find(grid[i+1][j]);
                    sum+=it->second;
                }
                if(checkvalid(i,j+1,m,n) && grid[i][j+1] >1 && s.find(grid[i][j+1]) == s.end()){
                    s.insert(grid[i][j+1]);
                    auto it = mp.find(grid[i][j+1]);
                    sum+=it->second;
                }
                if(checkvalid(i,j-1,m,n) && grid[i][j-1] >1 && s.find(grid[i][j-1]) == s.end()){
                    s.insert(grid[i][j-1]);
                    auto it = mp.find(grid[i][j-1]);
                    sum+=it->second;
                }

                Max = max(Max,sum+1); 
            }
        }
    }
    return (Max==INT_MIN) ? m*n :Max;
}

int main()
{
    vector<vector<int>> grid = {{1,0},{0,1}};
    int ans = largestIsland(grid);
    cout<< "ans is : " << ans << endl;
    return 0;
}
