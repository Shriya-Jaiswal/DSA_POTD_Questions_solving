#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// // ▶️ Ask by :  Amazon ✯   Baidu ✯  

// // ▶️ Approach-1 (Recursion + Memoization using 3D Array)
// // ⏲️ Time Complexity : O(m * n * maxMove)
// // 🛢️ Space Complexity : O(m * n * maxMove)

// int M;
// int N;
// int MOD = 1e9+7;
// vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// int t[51][51][51];
// int solve(int maxMove, int startRow, int startColumn) {
//     if(startRow < 0 || startRow >= M || startColumn < 0 || startColumn >= N) {
//         return 1; //Found one path out
//     }
//     if(maxMove <= 0) 
//         return 0;
//     if(t[maxMove][startRow][startColumn] != -1) {
//         return t[maxMove][startRow][startColumn];
//     }
//     int result = 0;
//     for(auto &dir : directions) {
//         int x = startRow    + dir[0];
//         int y = startColumn + dir[1];
//         result = (result + solve(maxMove-1, x, y)) % MOD;
//     }
//     return t[maxMove][startRow][startColumn] = result%MOD;
// }

// int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//     memset(t, -1, sizeof(t));
//     M = m;
//     N = n;
//     return solve(maxMove, startRow, startColumn);
// }



// // ▶️ Approach-2 (Bottom Up)
// // ⏲️ Time Complexity : O(m * n * maxMove)
// // 🛢️ Space Complexity : O(m * n * maxMove)


// int MOD = 1e9+7;
// vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//     int dp[50][50][51];
//     //dp[i][j][k] = the number of possible moves leading to a path out of the boundary if the current position is [i][j] and number of moves left is k.
//     memset(dp, 0, sizeof(dp));
//     for (int k = 1; k <= maxMove; ++k) {
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 for(auto &dir : directions) {
//                     int x = i + dir[0];
//                     int y = j + dir[1];
//                     if (x < 0 || x >= m || y < 0 || y >= n)
//                         dp[i][j][k] = (dp[i][j][k] + 1) % MOD;
//                     else
//                         dp[i][j][k] = (dp[i][j][k] + dp[x][y][k - 1]) % MOD;
//                 }
//             }
//         }
//     }
//     return dp[startRow][startColumn][maxMove];
// }


// ▶️ Approach-3 (Space optimized bottom up)
// ⏲️ Time Complexity : O(m * n * maxMove)
// 🛢️ Space Complexity : O(m * n)


int MOD = 1e9+7;
vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<int>> t(50, vector<int>(50));
    t[startRow][startColumn] = 1;
    int result = 0;
    for (int k = 1; k <= maxMove; ++k) {
        vector<vector<int>> temp(50, vector<int>(50));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {  
                for(auto &dir : directions) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        result = (result + t[i][j]) % MOD;
                    }
                    else {
                        temp[x][y] = (temp[x][y] + t[i][j]) % MOD;
                    }
                }
            }
        }
        t = temp;
    }
    return result;
}

int main()
{
    int  m = 2;
    int n = 2;
    int maxMove = 2;
    int startRow = 0;
    int startColumn = 0;
    int ans = findPaths(m,n,maxMove,startRow,startColumn);
    cout << "ans is : " << ans << endl;
    return 0;
}
