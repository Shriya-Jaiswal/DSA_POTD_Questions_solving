#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<math.h>
using namespace std;

// ▶️ Ask by :  Amazon ✯  

int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    int n = grid.size(), m = grid[0].size();
        
    if (i < 0 || i >= n || j >= m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int moves = 0;

    if (i > 0 && j < m - 1 && grid[i][j] < grid[i - 1][j + 1])
        moves = max(moves, solve(i - 1, j + 1, grid, dp));

    if (j < m - 1 && grid[i][j] < grid[i][j + 1])
        moves = max(moves, solve(i, j + 1, grid, dp));

    if (i < n - 1 && j < m - 1 && grid[i][j] < grid[i + 1][j + 1])
        moves = max(moves, solve(i + 1, j + 1, grid, dp));

    return dp[i][j] = 1 + moves;
}

int maxMoves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        res = max(res, solve(i, 0, grid, dp));
    }
    return res - 1;
}

int main()
{
    vector<vector<int>> grid = {{2,4,3,5},{5,4,9,3},{3,4,2,11},{1,9,13,15}};
    int ans = maxMoves(grid);
    cout << " ans is : " << ans << endl;
    return 0;
}
