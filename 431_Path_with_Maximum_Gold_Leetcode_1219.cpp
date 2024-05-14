#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  tiktok ✯  

// ▶️ Approach - Using DFS
// ⏲️ Time Complexity : O(m*n * 4^(cells with gold))
// 🛢️ Space Complexity : O(cells with gold) - the length of a path through gold will contribute to the recursive call stack

int m, n;
vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
int DFS(vector<vector<int>>& grid, int i, int j) {

    if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) {
        return 0; //Zero gold
    }

    int originalGoldValue = grid[i][j];
    grid[i][j] = 0;

    int maxGold = 0;

    //up, down, left, right
    for(vector<int>& dir : directions) {
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        maxGold = max(maxGold, DFS(grid, new_i, new_j));
    }
    grid[i][j] = originalGoldValue;
    return originalGoldValue + maxGold;
}

int getMaximumGold(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    int maxGold = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            if(grid[i][j] != 0) {
                //It has gold
                maxGold = max(maxGold, DFS(grid, i, j));
            }

        }
    }
    return maxGold;
}

int main()
{
    vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    int ans = getMaximumGold(grid);
    cout << "ans is : " << ans << endl;
    return 0;
}
